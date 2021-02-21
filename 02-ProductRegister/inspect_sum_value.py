#!/usr/bin/python3

import pexpect
import random
import re

while True:
    p = pexpect.spawn("./registry.out")
    p.setecho(False)
    result = p.expect([": ", "erro"])

    if result != 0:
        print("Just a moment, the adder is not being cooperative...")
        continue
   
    option = 0        
    p.sendline(str(option))
    p.expect(": ")
    name = "Computador"
    p.sendline(name)

    p.expect(": ")
    description = "Dell G5"
    p.sendline(description)

    p.expect(": ")
    price = 8000.0
    p.sendline(str(price))

    p.expect(": ")
    option = 5
    p.sendline(str(option))

    p.expect(": ")
    option = 6
    p.sendline(str(option))

    p.expect(pexpect.EOF)
    print("Teste finalizado")
    break;
  