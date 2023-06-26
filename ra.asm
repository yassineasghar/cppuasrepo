.data
	info_0:		.ascii 	"Something 1 \n"
			.ascii 	"Something 2 \n"
			.asciiz "Something 3"
	info_1:		.asciiz "Something 4 \n"
	info_2:		.asciiz "Something 5 \n"
	info_3:		.asciiz "Something 6 \t"

.text 
	li $v0, 4
	la $a0, info_0
	syscall 				# Output ==> info_0
	
	li $v0, 4
	la $a0, info_1
	syscall 				# Output ==> info_1
	
	addi $a0, $0, 120			# String MAX 120 bytes
	lui $a0, 0x1001				# Datensegment liegt an diese stelle 
	li $v0, 8
	syscall 				# Eingabe einlesen

	li $v0, 12
	syscall 
	add $t0, $0, $v0			# Zu vergleichender char in $t0

		# ----------- Evaluierung Zeichenkette ------------ #
	
	addi $s0, $0, 0   			# Erg. Reg.
	lui $t1, 0x1001				# pointer for Testchar  
	addi $t2, $0, 0				# TEST Reg.
start : 	
	lb $t2, ($t1)
	beq $t2, $0, done 			# The ende of string  / Ende Zeichenkette 
	beq $t0, $t2, count 			# Zeichen gefunden --> $s0 ++  
	addi $t1, $t1, 1
	j start 
	


done : 
	li $v0, 4
	la $a0, info_3
	syscall 
	
	li $v0, 1
	addi $a0, $s0, 0 
	syscall
count : 
	addi $s0, $s0, 1
	addi $t1, $t1, 1
	j start 
	
	
