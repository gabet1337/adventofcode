#!/usr/bin/python
import hashlib
import sys

for num in range(1,100000000):
    if (num%100000 == 0): print num
    m = hashlib.md5()
    m.update("bgvyzdsv"+str(num))
    s = m.hexdigest()
    if (s[0] == '0' and s[1] == '0' and s[2] == '0' and s[3] == '0' and s[4] == '0' and s[5] == '0'):
        print num
        print s
        sys.exit()
