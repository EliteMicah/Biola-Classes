.data                               # data segment
Msg1:
.string "\nEnter Value for x: "     # Prompt for value x
Msg2:
.string "\nEnter Value for y: "     # Prompt for value y
newLine:    
.string "\n"                        # Newline
outMsg1:
.string "x > y"                     # 1st Output message
outMsg2:
.string "x <= y"                    # 2nd Output message

.bss                    # uninitialized variables segment    
	.lcomm x, 32
	 movl $0, x
	.lcomm y, 32
	 movl $0, y
.text                   # code segment
.global main
main:            

# Prompt user for x
	movq $4, %rax       # sys_write    
	movq $1, %rbx       # $1 is stdout    
	movq $Msg1, %rcx    # message to write    
	movq $20, %rdx      # length of the message    
	int  $0x80          # system interrupt to kernel    
# Read x
	movq $3, %rax       # sys_read    
	movq $0, %rbx       # $0 is stdin    
	movq $x, %rcx       # m   
	movq $0x2, %rdx     # size    
	int $0x80           # system interrupt to kernel

# Prompt user for y
	movq $4, %rax       # sys_write    
	movq $1, %rbx       # $1 is stdout    
	movq $Msg2, %rcx    # message to write    
	movq $20, %rdx      # length of the message    
	int  $0x80          # system interrupt to kernel    
# Read y
	movq $3, %rax       # sys_read    
	movq $0, %rbx       # $0 is stdin    
	movq $y, %rcx       # y
	movq $0x2, %rdx     # size    
	int $0x80           # system interrupt to kernel

# If statement (moving to registers)

    movq x, %rdx        # move x to rdx register
    subq $0x30, %rdx    # subtract ASCII value for '0' to convert to number
    movq y, %rax        # move x to rdx register
    subq $0x30, %rax    # subtract ASCII value for '0' to convert to number
    
# Comparing
    cmpq %rax, %rdx     # compare x and y
    jg greater          # if x is greater than y, jump to greater
    jl lesser           # if y is greater than x, jump to lesser
    je equal            # if x is equal to y, jump to equal

greater:
# NewLine message
    movq $4, %rax       # sys_write    
    movq $1, %rbx       # $1 is stdout    
    movq $newLine, %rcx # output message    
    movq $1, %rdx       # length of the message    
    int  $0x80          # system interrupt to kernel   
# Output x (testing purposes)
#    movq $4, %rax       # sys_write    
#    movq $1, %rbx       # $1 is stdout    
#    movq $x, %rcx       # output x
#    movq $0x1, %rdx     # length of the message    
#    int  $0x80          # system interrupt to kernel   
# Output message
    movq $4, %rax       # sys_write    
    movq $1, %rbx       # $1 is stdout    
    movq $outMsg1, %rcx  # output message    
    movq $5, %rdx      # length of the message    
    int  $0x80          # system interrupt to kernel 
# Output y (testing purposes)
#    movq $4, %rax       # sys_write    
#    movq $1, %rbx       # $1 is stdout    
#    movq $y, %rcx       # output y
#    movq $0x1, %rdx     # length of the message    
#    int  $0x80          # system interrupt to kernel
    jmp end

lesser:
# NewLine message
    movq $4, %rax       # sys_write    
    movq $1, %rbx       # $1 is stdout    
    movq $newLine, %rcx # output message    
    movq $1, %rdx       # length of the message    
    int  $0x80          # system interrupt to kernel  
# Output x (testing purposes)
#    movq $4, %rax       # sys_write    
#    movq $1, %rbx       # $1 is stdout    
#    movq $x, %rcx       # output x
#    movq $0x1, %rdx     # length of the message    
#    int  $0x80          # system interrupt to kernel  
# Output message
    movq $4, %rax       # sys_write    
    movq $1, %rbx       # $1 is stdout    
    movq $outMsg2, %rcx # output message    
    movq $6, %rdx       # length of the message    
    int  $0x80          # system interrupt to kernel
# Output y (testing purposes)
#    movq $4, %rax       # sys_write    
#    movq $1, %rbx       # $1 is stdout    
#    movq $y, %rcx       # output y
#    movq $0x1, %rdx     # length of the message    
#    int  $0x80          # system interrupt to kernel
    jmp end

equal:
# NewLine message
    movq $4, %rax       # sys_write    
    movq $1, %rbx       # $1 is stdout    
    movq $newLine, %rcx # output message    
    movq $1, %rdx       # length of the message    
    int  $0x80          # system interrupt to kernel  
# Output x (testing purposes)
#    movq $4, %rax       # sys_write    
#    movq $1, %rbx       # $1 is stdout    
#    movq $x, %rcx       # output x
#    movq $0x1, %rdx     # length of the message    
#    int  $0x80          # system interrupt to kernel  
# Output message
    movq $4, %rax       # sys_write    
    movq $1, %rbx       # $1 is stdout    
    movq $outMsg2, %rcx # output message    
    movq $6, %rdx       # length of the message    
    int  $0x80          # system interrupt to kernel
# Output y (testing purposes)
#    movq $4, %rax       # sys_write    
#    movq $1, %rbx       # $1 is stdout    
#    movq $y, %rcx       # output y
#    movq $0x1, %rdx     # length of the message    
#    int  $0x80          # system interrupt to kernel

end:

# Exit with return 0
	movl $1, %eax       # exit(0) - $1 is sys_exit    
	movl $0, %ebx       # 0 is return value    
	int  $0x80          # system interrupt to kernel    
	ret
	
