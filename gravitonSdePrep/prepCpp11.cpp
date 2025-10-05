#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <iostream>
#include <semaphore>
#include <queue>

using namespace std;

// we will try to understand the use of multithreading and concurrency features in C++11

// spin lock
class SpinLock{
	atomic_flag flag = ATOMIC_FLAG_INIT;

public:

	void lock(){
		while(flag.test_and_set(memory_order_acquire));
	}

	void unlock(){
		flag.clear(memory_order_release);
	}

};

int counter = 0;
SpinLock spinLock;

void increment(){
	for(int i=0; i<100000; i++){
		spinLock.lock();
		counter++;
		spinLock.unlock();
	}
}

// understanding mutex
int counter2 = 0;
mutex mtx;

void increment2(){
	for(int i=0; i<100000; i++){
		mtx.lock();
		counter2++;
		mtx.unlock();
	}
}

// semaphores
// semaphores are like mutex but they allow multiple threads to access a resource as opposed to just one thread in case of mutex

//condition variables
// they are used to block a thread until a particular condition is met
queue<int> q;
mutex mtx2;
condition_variable cv;
bool done = false;

void producer(){
	for(int i=0; i<=5; i++){
		mtx2.lock();
		q.push(i);
		cout<<"Produced: "<<i<<endl;
		mtx2.unlock();
		cv.notify_one(); // notify one waiting thread
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	mtx2.lock();
	done = true;
	mtx2.unlock();
	cv.notify_all(); // notify all waiting threads
}

void consumer(){
	while(true){
		unique_lock<mutex> lck(mtx2);
		cv.wait(lck, []{return !q.empty() || done;}); // wait until queue is not empty or done is true
		while(!q.empty()){
			int val = q.front();
			q.pop();
			cout<<"Consumed: "<<val<<endl;
		}
		if(done) break;
	}
}


int main(){

	thread t1(increment);
	thread t2(increment);
	t1.join();
	t2.join();
	cout<<counter<<endl;

	thread t3(increment2);
	thread t4(increment2);
	t3.join();
	t4.join();
	cout<<counter2<<endl;

	// thread library creates kernel threads

	thread prod(producer);
	thread cons(consumer);
	prod.join();
	cons.join();

	return 0;
}