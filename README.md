# Operating-Systems-Banker-s-Algorithm

ABSTRACT-
In computer science and operating systems, deadlock avoidance is a critical concept aimed at preventing the occurrence of deadlocks within a system. A deadlock is a state where two or more processes cannot proceed with their execution because each is waiting for a resource held by another, resulting in a circular dependency. This project explores the fundamental components of deadlock avoidance, including resources, requests, and allocations, and how these elements interact within a system. Resources encompass a variety of entities such as memory, CPU cycles, files, or I/O devices that processes require during execution. A process initiates a request for these resources, and upon availability, the operating system allocates the resources, enabling the process to continue. Deadlock arises when processes are trapped in a cycle of resource requests, unable to progress. This report delves into the mechanisms and strategies for deadlock avoidance, ensuring system stability and process efficiency by preventing such cyclic dependencies.

INTRODUCTION-
Deadlock avoidance is a concept in computer science and operating systems that deals with preventing the occurrence of deadlocks in a system. A deadlock is a situation where two or more processes are unable to proceed because they are each waiting for a resource held by another process, creating a circular dependency.
To better understand deadlock avoidance, let us break down the key components:
Resource: A resource can be anything that a process requests and uses during its execution, such as memory, CPU cycles, files, or I/O devices.
Request: When a process needs a resource to complete its task, it sends a request to the operating system.
Allocation: If the requested resource is available, the operating system grants it to the process, and the process can continue its execution.
Deadlock: Deadlock occurs when two or more processes are stuck in a cyclic dependency of resource requests and are unable to make any progress.

OS CONCEPTS USED-

In our project scope focused on deadlock avoidance, the following key operating system (OS) concepts are utilized:
Processes and Resource Management:
● Each process is represented as a structure (process) with attributes such as Max, Allocation, Need, and status. This models how processes request, hold, and release resources in an operating system.
Resource Allocation:
● The code manages resource allocation and availability through vectors representing the currently allocated resources (Allocation) and the total available resources (available).
Concurrency and Synchronization:
● Although the code does not explicitly handle concurrency, it deals with resource allocation which is a core aspect of process synchronization in OS to avoid conflicts and deadlocks.
Deadlock Avoidance (Banker's Algorithm):
● The IsSafe function implements the Banker's Algorithm, a classic deadlock avoidance algorithm. This function checks if the system is in a safe state by simulating
resource allocation and ensuring that processes can proceed to completion without causing a deadlock.
Safe and Unsafe States:
● The concept of safe and unsafe states is central to the Banker's Algorithm. The IsSafe functiondeterminesifthecurrentresourceallocationleadstoasafestate where all processes can complete without causing a deadlock.
System Calls and Input Handling:
● The code uses standard input and output for reading resource and process information. This simulates system calls that processes use to request resources from the OS

INPUT-
<img width="569" alt="Screenshot 2024-07-20 at 11 07 55 PM" src="https://github.com/user-attachments/assets/ee5fedbc-d2b2-41e0-b9d8-50fbe3d73daa">

OUTPUT-
<img width="548" alt="Screenshot 2024-07-20 at 11 08 56 PM" src="https://github.com/user-attachments/assets/5ae5dbb2-658b-41fc-8f92-59b83f54a797">


