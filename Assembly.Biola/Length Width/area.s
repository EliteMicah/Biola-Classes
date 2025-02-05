.data                               # data segment
varL:
.string "\nEnter Value for l: "     # Prompt for value l
varW:
.string "\nEnter Value for w: "     # Prompt for value w
newLine:    
.string "\n"                        # Newline
multiplyMsg:
.string " * "                       # * Output message
equalsMsg:
.string " = "                       # = Output message

.bss                    # uninitialized variables segment    
	.lcomm l, 32
	 movl $0, l
	.lcomm w, 32
	 movl $0, w
	.lcomm a, 32
	 movl $0, a
	 
.text                   # code segment
.global main
main:            

# Prompt user for l
	movq $4, %rax       # sys_write    
	movq $1, %rbx       # $1 is stdout    
	movq $varL, %rcx    # message to write    
	movq $20, %rdx      # length of the message    
	int  $0x80          # system interrupt to kernel    
# Read l
	movq $3, %rax       # sys_read    
	movq $0, %rbx       # $0 is stdin    
	movq $l, %rcx       # l
	movq $0x2, %rdx     # size    
	int $0x80           # system interrupt to kernel

# Prompt user for w
	movq $4, %rax       # sys_write    
	movq $1, %rbx       # $1 is stdout    
	movq $varW, %rcx    # message to write    
	movq $20, %rdx      # length of the message    
	int  $0x80          # system interrupt to kernel    
# Read w
	movq $3, %rax       # sys_read    
	movq $0, %rbx       # $0 is stdin    
	movq $w, %rcx       # w
	movq $0x2, %rdx     # size    
	int $0x80           # system interrupt to kernel

# MULTIPLY x * y = 
# NewLine message
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $newLine, %rcx     # output message    
    movq $1, %rdx           # length of the message    
    int  $0x80              # system interrupt to kernel  
# Output l
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $l, %rcx           # output l
    movq $0x1, %rdx         # length of the message    
    int  $0x80              # system interrupt to kernel  
# Output message *
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $multiplyMsg, %rcx # output message    
    movq $3, %rdx           # length of the message    
    int  $0x80              # system interrupt to kernel
# Output w
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $w, %rcx           # output w
    movq $0x1, %rdx         # length of the message    
    int  $0x80              # system interrupt to kernel
# Output message = 
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $equalsMsg, %rcx   # output message    
    movq $3, %rdx           # length of the message    
    int  $0x80              # system interrupt to kernel

# Moving l and w to registers
    movq l, %rdx            # move l to rdx register
    subq $0x30, %rdx        # subtract ASCII value for '0' to convert to number
    
    movq w, %rax            # move w to rax register
    subq $0x30, %rax        # subtract ASCII value for '0' to convert to number

# Calculation
    imulq %rax, %rdx        # multiply by x and store result in rdx register
    addq $0x30, %rdx        # add ASCII value for '0' to convert back to ASCII
    movq %rdx, a            # store ASCII value into a

# Output a
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $a, %rcx           # output a
    movq $0x1, %rdx         # length of the message    
    int  $0x80              # system interrupt to kernel

# Exit with return 0
	movl $1, %eax       # exit(0) - $1 is sys_exit    
	movl $0, %ebx       # 0 is return value    
	int  $0x80          # system interrupt to kernel    
	ret
	
