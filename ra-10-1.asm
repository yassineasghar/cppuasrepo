.data
a0: .float 2.0   # Example values for the coefficients a0, a1, a2
a1: .float 5.0
a2: .float 2.0
result1: .float 0.0
result2: .float 0.0
sqrt_iters: .word 5

.text
.globl main

# Heron-Verfahren zur Berechnung der Quadratwurzel
heron:
    # Laden der Eingangsparameter
    lwc1 $f0, 0($a0)     # x
    
    # Initialisierung
    li $t0, 0           # Iterationszähler
    lw $t1, sqrt_iters   # Anzahl der Iterationen laden
    
heron_loop:
    # Heron-Schritt
    lwc1 $f2, 0($a0)    # x
    div.s $f3, $f2, $f1 # x / s
    add.s $f4, $f1, $f3 # s + (x / s)
    mul.s $f5, $f4, $f6 # (s + (x / s)) * 0.5
    mov.s $f1, $f5      # s = (s + (x / s)) * 0.5
    
    addi $t0, $t0, 1    # Iterationszähler erhöhen
    bne $t0, $t1, heron_loop  # Schleife fortsetzen, wenn Iterationszähler != sqrt_iters
    
    # Ergebnis in $f1 speichern
    swc1 $f1, 0($a1)
    jr $ra

# Hauptprogramm
main:
    # p/q-Formel
    
    # Laden der Koeffizienten
    lwc1 $f6, a1        # a1
    lwc1 $f7, a2        # a2
    div.s $f8, $f6, $f7 # p = a1 / a2
    
    lwc1 $f9, a0        # a0
    div.s $f10, $f9, $f7 # q = a0 / a2
    
    # Laden der Konstante 1.0 als Fließkommazahl
    li $t2, 0x3f800000  # 1.0 als IEEE 754 Fließkommazahl
    
    mtc1 $t2, $f1      # Konvertierung zu einer Fließkommazahl
    
    # (p/2)^2
    mul.s $f11, $f8, $f1   # p/2
    mul.s $f11, $f11, $f11 # (p/2)^2
    
    # Berechnung der Diskriminante
    sub.s $f12, $f11, $f10 # (p/2)^2 - q
    
    # Übergabe der Diskriminante an das Heron-Verfahren
    la $a0, sqrt_iters
    la $a1, result2
    
    jal heron
    
    # Berechnung der Lösungen
    lwc1 $f13, 0($a1)    # Wurzel
    
    sub.s $f14, $f13, $f8   # wurzel - p/2
    add.s $f15, $f13, $f8   # wurzel + p/2
    
    # Speichern der Lösungen
    swc1 $f14, result1
    swc1 $f15, result2
    
    # Ende des Programms
    li $v0, 10
    syscall
