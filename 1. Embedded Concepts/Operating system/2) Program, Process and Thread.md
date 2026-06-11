**In the world of operating systems, understanding the distinction between processes, programs, and threads is essential. 
These are the key components involved in the execution of tasks by a computer system. **

These are essential when it comes to systems performance

**Process**
 - A process is a program that is currently being executed by the operating system.

 - When a program is launched (for example, by clicking on a game or a browser),
   the operating system loads the necessary code into memory, creates a process, assigns it resources, and begins executing its instructions.
   The process is monitored and controlled by the OS throughout its lifecycle.

**Program**
 - A program is a static set of instructions written in a programming language, stored on a disk or other storage medium.
   It is a passive entity that only defines what the computer is supposed to do.
   It becomes an active process only when the OS loads and executes it.

 - **Analogy:** A program is like a recipe written in a cookbook. It contains instructions for preparing a dish (task),
   but nothing happens until someone reads it and follows the steps (i.e., the OS executes it).

  ----------------------------------------------------------------------------------------------------------------------------------------- 

**Process vs Program**

Although often used interchangeably, a program and a process are quite different in the context of an operating system.

A **program** is merely the code, like a text document sitting on disk. 
A **process** is the active execution of that code, along with all the memory, CPU, and resources needed to carry it out.
<img width="1237" height="856" alt="image" src="https://github.com/user-attachments/assets/4ebb4ff0-732c-4a8b-a117-93ba1ebbb918" />

----------------------------------------------------------------------------------------------------------------------------------------------

**Thread**
 - A **thread** is the smallest unit of execution within a process. If a process is a large task, then threads are the smaller subtasks within it.
   A process can have one or multiple threads. Each thread represents a single sequence of instructions executed independently.

   **Example: In a web browser:**
        One thread may handle loading a webpage.
        Another thread may play a video.
   Threads are used to improve the performance and efficiency of an OS.

