# OS Assignment-1 (Theory)
## AI20BTECH11006

# Problem-1
**(a) Describe a mechanism for enforcing memory protecction in order to prevent a program from modifying the memory associated with other programs.**

The processor could keep track of what locations are associated with each process
and limit access to locations that are outside of a program’s extent. Information regarding
the extent of a program’s memory could be maintained by using base and limits registers and by performing a check for every memory access.   

**Question: Do you see any other mechanism for enforcing the above requirement?**		
Answer) An obscure memory protection method utilised in modern commercial computers is capability-based addressing. In this instance, the pointers are restored by the capabilities objects, which have the advantage of preventing unauthorised processes from creating additional separate address spaces in memory. These capabilities objects can only be created with the protected instructions(kernel bit 1) and may only be executed by a kernel or by another process that is authorised to execute.

**(b) While memory protection is necessary, there are several examples where programs
require memory to be shared between them. Please give two such examples.**

**Solution:**              
1. transfer images between the application and the X server on Unix systems          
2. inside the IStream object returned by CoMarshalInterThreadInterfaceInStream in the COM libraries under Windows.         
3. In Go-Back-N protocol in rdtp 3.0, we need multiple processes to update and/or read BASE value of the window.           
4. In Spell Check program, two processes are reading, writing to the text.           

*Source:* https://en.wikipedia.org/wiki/Shared_memory

# Problem-2
**Please study the PCB (Process Control Block) structure of a Linux system from any reliable Internet source. Describe any 10 fields in the PCB of a process in the latest Linux Operating System. Please cite your source as well like in question 2.**        
- **Process ID:** This ID helps the process to be distinguished from other processes that exist in the system.           
- **Process State:** The state may be new, ready, running, waiting, halted, and so on.       
- **Program Counter:** The counter indicates the address of the next instruction to e executed for this process.          
- **CPU Registers:** The registers vary in number and type, depending on the computer architecture. They include accumulators, index registers, stack pointers, and general-purpose registers, plus any condition-code information. Along with the program counter, this state information must be saved when an interrupt occurs, to allow the process to be continued correctly afterward when it is rescheduled to run.        
- **CPU-scheduling information:** This information includes a process priority, pointer to scheduling queues, and any other scheduling parameters.        
- **Memory-management information:** This information may include such items as the value of the base and limit registers and the page tables, or the segment tables, depending on the memory system used by the operating system.           
- **Accounting Information:** This information includes the amount of CPU and real time used, time limits, account numbers, job or process numbers, and so on.       
- **I/O Status information:** This information includes the list of I/O devices allocated to the process.              
- **PCB pointer:** This field contains the address of the next PCB, which is in ready state. This helps the operating system to hierarchically maintain an easy control flow between parent processes and child processes.            
- **List of Open Files:** It contains the information of all the files which are required by the program during its execution.         
- **Process Privileges:**  allowed/disallowed access to system resources      
- **Interprocess communication information:** flags, signals and messages associated with the communication among independent processes.

Sources:            
1. https://binaryterms.com/process-control-block-pcb.html           
2. OS Book          
3. https://www.scaler.com/topics/operating-system/process-control-block-in-os/         
4. https://en.wikipedia.org/wiki/Process_control_block
