.data                                               # data segment
num1:
.string "\nEnter num1: "                            # Prompt for num1
num2:
.string "\nEnter num2: "                            # Prompt for num2
restartMsg:
.string "\nRestart? (0yes, 1no)"                    # Restart Msg
avgMsg:
.string "\nAverage is: "                            # AVG Output message
array:
    .long 1, 1, 2, 3                                # initialize the array with the four values

.bss                            # uninitialized variables segment    
	.lcomm restart, 32
	 movl $0, restart
	.lcomm numA, 32
	 movl $0, numA
	.lcomm numB, 32
	 movl $0, numB
	.lcomm avg, 32
	 movl $0, avg
	.lcomm total, 32
	 movl $0, total

.text                           # code segment
.global main
main:
myLoop:

    # Output the first two messages
    movq $4, %rax               # sys_write    
    movq $1, %rbx               # $1 is stdout    
    movq $num1, %rcx            # output num1
    movq $0x10, %rdx            # length of the message    
    int  $0x80                  # system interrupt to kernel 
    
    # Read num1
	movq $3, %rax               # sys_read    
	movq $0, %rbx               # $0 is stdin    
	movq $numA, %rcx            # numA
	movq $0x1, %rdx             # size    
	int $0x80                   # system interrupt to kernel

    # num2
    movq $4, %rax               # sys_write    
    movq $1, %rbx               # $1 is stdout    
    movq num2, %rcx             # output num2
    movq $0x11, %rdx            # length of the message    
    int  $0x80                  # system interrupt to kernel
    
    # Read num2
	movq $3, %rax               # sys_read    
	movq $0, %rbx               # $0 is stdin    
	movq $numB, %rcx            # numB 
	movq $0x2, %rdx             # size    
	int $0x80                   # system interrupt to kernel

# Addition of num1 & num2
    # Moving numA and numB to registers
    movq numA, %rdx             # move numA to rdx register
    subq $0x30, %rdx            # subtract ASCII value for '0' to convert to number
    
    movq numB, %rax             # move numB to rax register
    subq $0x30, %rax            # subtract ASCII value for '0' to convert to number

# Calculation
    addq %rax, %rdx             # add y and store result in rdx register
    addq $0x30, %rdx            # add ASCII value for '0' to convert back to ASCII
    movq %rdx, total            # store ASCII value into total
    
# Division
    movq total, %rax            # Move total into %rax
    movq 2, %rbx                # Move 2 into %rbx
    
    idivq %rbx                  # Divide total by numB
    movq %rbx, avg

# Print result
    # Output the result
    movq $4, %rax               # sys_write    
    movq $1, %rbx               # $1 is stdout    
    movq $avgMsg, %rcx          # output avgMsg
    movq $0x16, %rdx            # length of the message    
    int  $0x80                  # system interrupt to kernel

    movq $4, %rax               # sys_write    
    movq $1, %rbx               # $1 is stdout    
    movq avg, %rcx              # output avg
    movq $0x1, %rdx             # length of the message    
    int  $0x80                  # system interrupt to kernel 

# Asking user if he wants to restart
    movq $4, %rax               # sys_write    
    movq $1, %rbx               # $1 is stdout    
    movq restartMsg, %rcx       # output restartMsg
    movq $0x20, %rdx            # length of the message    
    int  $0x80                  # system interrupt to kernel 
    
    # Read restart
	movq $3, %rax               # sys_read    
	movq $0, %rbx               # $0 is stdin    
	movq $restart, %rcx         # restart
	movq $0x20, %rdx            # size
	int $0x80                   # system interrupt to kernel

# If statement
    movq restart, %rdx          # move restart to rdx register
    subq $0x30, %rdx            # subtract ASCII value for '0' to convert to number
    
# Comparing
    cmpq %rax, %rdx             # compare restart and 1
    jl myLoop                   # if restart is less than 1, jump to myLoop
    je loopDone                 # if restart is equal to 1, jump to equal

loopDone:
# Exit with return 0
    movl $1, %eax               # exit(0) - $1 is sys_exit    
    movl $0, %ebx               # 0 is return value    
    int  $0x80                  # system interrupt to kernel    
    ret
