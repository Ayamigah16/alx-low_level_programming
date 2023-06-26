import uncompyle6

with open("crackme4", "rb") as f:
    code = f.read()

uncompyle6.decompile(3.4, code, sys.stdout)
