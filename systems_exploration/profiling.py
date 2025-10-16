import cProfile

def slow_function():
    for _ in range(10**8):
        pass

def main():
    slow_function()

if __name__ == "__main__":
    cProfile.run("main()")
