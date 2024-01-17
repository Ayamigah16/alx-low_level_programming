# 0x00. C - Hello, World
`C` `Shell`

![C image](https://www.articlering.com/wp-content/uploads/2021/08/c-programming.png)

## Tasks

### **0. Preprocessor** :heart_on_fire:

- Write a script that runs a C file through the preprocessor and save the result into another file.

* The C file name will be saved in the variable $CFILE
* The output should be saved in the file c

* **File:** `0-preprocessor`
    
### ***1. Compiler** :boom: :boom:

- Write a script that compiles a C file but does not link.

* The C file name will be saved in the variable **$CFILE**
* The output file should be named the same as the C file, but with the extension .o instead of **.c**

* **File:** `1-compiler`
    
### **2. Assembler** :yum: :yum: :ok_hand:

- Write a script that generates the assembly code of a C code and save it in an output file.

* The C file name will be saved in the variable **$CFILE**
* The output file should be named the same as the C file, but with the extension **.s** instead of **.c**
 
* **File:** `2-assembler` 
    
###  **3. Name** :smiley: :heart_on_fire:

- Write a script that compiles a C file and creates an executable named **cisfun**.

* The C file name will be saved in the variable **$CFILE**

* **File:** `3-name`
    
###  **4. Hello, puts** :astronaut:

- Write a C program that prints exactly ***"Programming is like building a multilingual puzzle,*** followed by a new line.

* Use the function **puts**
* You are not allowed to use **printf**
* Your program should end with the value **0**
 
* **File:** `4-puts.c`
    
###  **5. Hello, printf** :heart_on_fire:

- Write a C program that prints exactly ***with proper grammar, but the outcome is a piece of art,***, followed by a new line.

* Use the function **printf**
* You are not allowed to use the function **puts**
* Your program should return **0**
* Your program should compile without warning when using the **-Wall** **gcc** option
 
* **File:** `5-printf.c`
    
###  **6. Size is not grandeur, and territory does not make a nation** :yum: :yum:
 
- Write a C program that prints the size of various types on the computer it is compiled and run on.

* You should produce the exact same output as in the example
* Warnings are allowed
* Your program should return **0**

```
    julien@ubuntu:~/c/0x00$ gcc 6-size.c -m32 -o size32 2> /tmp/32
    julien@ubuntu:~/c/0x00$ gcc 6-size.c -m64 -o size64 2> /tmp/64
    julien@ubuntu:~/c/0x00$ ./size32
    Size of a char: 1 byte(s)
    Size of an int: 4 byte(s)
    Size of a long int: 4 byte(s)
    Size of a long long int: 8 byte(s)
    Size of a float: 4 byte(s)
    julien@ubuntu:~/c/0x00$ ./size64
    Size of a char: 1 byte(s)
    Size of an int: 4 byte(s)
    Size of a long int: 8 byte(s)
    Size of a long long int: 8 byte(s)
    Size of a float: 4 byte(s)
    julien@ubuntu:~/c/0x00$ echo $?
    0
    julien@ubuntu:~/c/0x00$ 
```

* **File:** `6-size.c`
    
### **7. Intel** :yum: :yum: :butterfly:
 
- Write a script that generates the assembly code (Intel syntax) of a C code and save it in an output file.

* The C file name will be saved in the variable **$CFILE**.
* The output file should be named the same as the C file, but with the extension **.s** instead of **.c**

* **File:** `100-intel`

### **8. UNIX is basically a simple operating system, but you have to be a genius to understand the simplicity** :clap: :clap:
 
- Write a C program that prints exactly ***and that piece of art is useful" - Dora Korpar, 2015-10-19,*** followed by a new line, to the standard error.

* You are not allowed to use any functions listed in the NAME section of the man (3) **printf** or man (3) **puts**
* Your program should return **1**
* Your program should compile without any warnings when using the **-Wall** **gcc** option

* **File:** `101-quote.c`
