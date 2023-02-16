#!/usr/bin/python3
"This is a line of text"


def validUTF8(data):
    "This is a line of text"
    lst_bytes = []
    for num in data:
        try:
            lst_bytes.append((num).to_bytes(1, byteorder='big'))
        except Exception:
            lst_bytes.append((num).to_bytes(2, byteorder='big'))
    check_utf8 = b''.join(lst_bytes)
    try:
        check_utf8.decode("utf-8")
    except Exception:
        return False
    return True
