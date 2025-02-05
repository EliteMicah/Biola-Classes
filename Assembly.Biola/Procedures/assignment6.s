.data                               # data segment
varX:
.string "\nEnter Value for x: "     # Prompt for value x
varY:
.string "\nEnter Value for y: "     # Prompt for value y
newLine:    
.string "\n"                        # Newline
plusMsg:
.string " + "                       # + Output message
minusMsg:
.string " - "                       # - Output message
multiplyMsg:
.string " * "                       # * Output message
equalsMsg:
.string " = "                       # = Output message

.bss                    # uninitialized variables segment    
	.lcomm x, 32
	 movl $0, x
	.lcomm y, 32
	 movl $0, y
	.lcomm z, 32
	 movl $0, z
	 
.text                   # code segment
.global main
main:            

# Prompt user for x
	movq $4, %rax       # sys_write    
	movq $1, %rbx       # $1 is stdout    
	movq $varX, %rcx    # message to write    
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
	movq $varY, %rcx    # message to write    
	movq $20, %rdx      # length of the message    
	int  $0x80          # system interrupt to kernel    
# Read y
	movq $3, %rax       # sys_read    
	movq $0, %rbx       # $0 is stdin    
	movq $y, %rcx       # y
	movq $0x2, %rdx     # size    
	int $0x80           # system interrupt to kernel


# PLUS x + y = 
    call plus
plus:
# NewLine message
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $newLine, %rcx     # output message    
    movq $1, %rdx           # length of the message    
    int  $0x80              # system interrupt to kernel   
# Output x
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $x, %rcx           # output x
    movq $0x1, %rdx         # length of the message    
    int  $0x80              # system interrupt to kernel   
# Output message +
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $plusMsg, %rcx     # output message    
    movq $3, %rdx           # length of the message    
    int  $0x80              # system interrupt to kernel 
# Output y 
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $y, %rcx           # output y
    movq $0x1, %rdx         # length of the message    
    int  $0x80              # system interrupt to kernel
# Output message = 
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $equalsMsg, %rcx   # output message    
    movq $3, %rdx           # length of the message    
    int  $0x80              # system interrupt to kernel
# Moving x and y to registers
    movq x, %rdx            # move x to rdx register
    subq $0x30, %rdx        # subtract ASCII value for '0' to convert to number
    
    movq y, %rax            # move y to rax register
    subq $0x30, %rax        # subtract ASCII value for '0' to convert to number

# Calculation
    addq %rax, %rdx         # add y and store result in rdx register
    addq $0x30, %rdx        # add ASCII value for '0' to convert back to ASCII
    movq %rdx, z            # store ASCII value into z

# Output z
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $z, %rcx           # output z
    movq $0x1, %rdx         # length of the message    
    int  $0x80              # system interrupt to kernel

# Reset
    movl $0, z              # Reset z to 0
    movq $0, %rdx           # move value 0 to rdx register
    movq $0, %rax           # move value 0 to rax register


# MINUS x - y = 
    call minus
minus:
# NewLine message
    movq $4, %rax           # sys_write
    movq $1, %rbx           # $1 is stdout
    movq $newLine, %rcx     # output message
    movq $1, %rdx           # length of the message
    int  $0x80              # system interrupt to kernel
# Output x
    movq $4, %rax           # sys_write
    movq $1, %rbx           # $1 is stdout
    movq $x, %rcx           # output x
    movq $0x1, %rdx         # length of the message
    int  $0x80              # system interrupt to kernel
# Output message - 
    movq $4, %rax           # sys_write
    movq $1, %rbx           # $1 is stdout
    movq $minusMsg, %rcx    # output message
    movq $3, %rdx           # length of the message
    int  $0x80              # system interrupt to kernel
# Output y
    movq $4, %rax           # sys_write
    movq $1, %rbx           # $1 is stdout
    movq $y, %rcx           # output y
    movq $0x1, %rdx         # length of the message
    int  $0x80              # system interrupt to kernel
# Output message = 
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $equalsMsg, %rcx   # output message    
    movq $3, %rdx           # length of the message    
    int  $0x80              # system interrupt to kernel
# Moving x and y to registers
    movq x, %rdx            # move x to rdx register
    subq $0x30, %rdx        # subtract ASCII value for '0' to convert to number
    
    movq y, %rax            # move y to rax register
    subq $0x30, %rax        # subtract ASCII value for '0' to convert to number

# Calculation
    subq %rax, %rdx         # subtract y and store result in rdx register
    addq $0x30, %rdx        # add ASCII value for '0' to convert back to ASCII
    movq %rdx, z            # store ASCII value into z

# Output z
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $z, %rcx           # output z
    movq $0x1, %rdx         # length of the message    
    int  $0x80              # system interrupt to kernel

# Reset
    movl $0, z              # Reset z to 0
    movq $0, %rdx           # move value 0 to rdx register
    movq $0, %rax           # move value 0 to rax register

# MULTIPLY x * y = 
    call multiply
multiply:
# NewLine message
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $newLine, %rcx     # output message    
    movq $1, %rdx           # length of the message    
    int  $0x80              # system interrupt to kernel  
# Output x
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $x, %rcx           # output x
    movq $0x1, %rdx         # length of the message    
    int  $0x80              # system interrupt to kernel  
# Output message *
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $multiplyMsg, %rcx # output message    
    movq $3, %rdx           # length of the message    
    int  $0x80              # system interrupt to kernel
# Output y
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $y, %rcx           # output y
    movq $0x1, %rdx         # length of the message    
    int  $0x80              # system interrupt to kernel
# Output message = 
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $equalsMsg, %rcx   # output message    
    movq $3, %rdx           # length of the message    
    int  $0x80              # system interrupt to kernel

# Moving x and y to registers
    movq x, %rdx            # move x to rdx register
    subq $0x30, %rdx        # subtract ASCII value for '0' to convert to number
    
    movq y, %rax            # move y to rax register
    subq $0x30, %rax        # subtract ASCII value for '0' to convert to number

# Calculation
    imulq %rax, %rdx        # multiply by x and store result in rdx register
    addq $0x30, %rdx        # add ASCII value for '0' to convert back to ASCII
    movq %rdx, z            # store ASCII value into z

# Output z
    movq $4, %rax           # sys_write    
    movq $1, %rbx           # $1 is stdout    
    movq $z, %rcx           # output z
    movq $0x1, %rdx         # length of the message    
    int  $0x80              # system interrupt to kernel
    
    call end

end:
# Exit with return 0
	movl $1, %eax       # exit(0) - $1 is sys_exit    
	movl $0, %ebx       # 0 is return value    
	int  $0x80          # system interrupt to kernel    
	ret
	
