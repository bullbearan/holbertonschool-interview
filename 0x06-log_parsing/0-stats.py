#!/usr/bin/python3
"This is a line of text"
from sys import stdin


status_code = {"200": 0,
               "301": 0,
               "400": 0,
               "401": 0,
               "403": 0,
               "404": 0,
               "405": 0,
               "500": 0, }
size = 0
count = 1


def print_status():
    "This is a line of text"
    print("File size: {}".format(size))
    for code, status in sorted(status_code.items()):
        if status != 0:
            print("{}: {}".format(code, status))


if __name__ == "__main__":
    "This is a line of text"
    try:
        for line in stdin:
            try:
                lst = line.split()
                s_status_code = lst[-2]
                if s_status_code in status_code:
                    status_code[s_status_code] += 1
                size += int(lst[-1])
            except Exception:
                pass
            if count % 10 == 0:
                print_status()
            count += 1
    except Exception:
        print_status()
        raise
    print_status()
