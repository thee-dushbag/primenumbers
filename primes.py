"""Functions to optimize prime number generation"""


from math import floor
from time import time
from typing import Any, Callable
from sys import argv


class Log:
    """Log my programs progress"""

    def __init__(self, size: int = 9, cap: bool = True) -> None:
        """Initialize the size needed for the msg head"""
        if size % 2 == 0:
            size += 1
        self.size = size if size < 9 else 9
        self.cap = cap

    def show(self, head: Any, msg: Any) -> None:
        """Print the programs state"""
        head, msg = str(head), str(msg)
        if self.cap:
            head = head.upper()
        if len(head) > self.size:
            _t = floor(self.size / 2) - 1
            head = head[:_t] + "..." + head[-_t:]
        print(f"[ {head.ljust(self.size, ' ')} ] : {msg}")

    def __call__(self, head: str, msg: str) -> Any:
        """Make the instance callable"""
        self.show(head, msg)


log = Log()


def get_primes_all(num: int) -> list:
    """Generate num prime numbers
    by testing all the numbers"""
    found = [2]
    cur = 3
    while len(found) < num:
        for i in range(2, cur):
            if cur % i == 0:
                break
            elif i == (cur - 1):
                # log("found", f"{len(found)} Primes Found")
                found.append(cur)
        cur += 1
    return found


def get_primes_odd(num: int) -> list:
    """Generate num prime numbers
    by testing all the pre odd numbers"""
    found = [2, 3]
    cur = 5
    while len(found) <= num:
        for i in range(3, cur, 2):
            if cur % i == 0:
                break
            elif i == (cur - 2):
                # log("found", f"{len(found)} Primes Found")
                found.append(cur)
        cur += 2
    return found


def get_primes_half_odd(num: int) -> list:
    """Generate num prime numbers
    by testing half of the pre odd numbers"""
    found = [2, 3]
    cur = 5
    while len(found) <= num:
        for i in range(3, cur, 2):
            if cur % i == 0:
                break
            elif i > cur / 2:
                # log("found", f"{len(found)} Primes Found")
                found.append(cur)
                break
        cur += 2
    return found


def get_primes_half_primes_found(num: int) -> list:
    """Generate num prime numbers
    by testing all the primes found"""
    found = [2, 3]
    cur = 5
    while len(found) <= num:
        for i in found:
            if cur % i == 0:
                break
            elif i > (cur / 2):
                # log("found", f"{len(found)} Primes Found")
                found.append(cur)
                break
        cur += 2
    return found


def timer(func: Callable, *arg: Any) -> tuple:
    """Time the execution of different functions func passed in"""
    start = time()
    ret = func(*arg)
    elapsed = time() - start
    info: str = f"{func.__name__}{arg} Took {elapsed} seconds."
    return ret, info, elapsed


def speedtest(functions: dict):
    """Execute function"""
    funcdata, timedata = dict(), list()
    logger = Log(15)
    i = 0
    for funcname in functions:
        logger("running", f"{funcname.__name__}{functions[funcname]}")
        _, info, timetaken = timer(funcname, *functions[funcname])
        funcdata[f"{funcname.__name__}{functions[funcname]}"] = (timetaken, i)
        logger("tested", f"{info}")
        timedata.append(timetaken)
        i += 1
    highest = max(timedata)
    logger("nb", "Compared with the slowest function.")
    for func in funcdata.items():
        ratio = highest / timedata[func[1][1]]
        logger("ratio", f"{str(ratio)[:4].ljust(4,'0')}x | {func[0]}")


if __name__ == "__main__":
    if len(argv) != 2:
        print(f'Syntax: {argv[0]} <number>')
        exit(1)
    q = int(argv[1])
    speedtest(
        {
            get_primes_all: (q,),
            get_primes_odd: (q,),
            get_primes_half_odd: (q,),
            get_primes_half_primes_found: (q,),
        }
    )
