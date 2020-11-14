extern irq_horloge, irq_clavier, default_irq
global _irq_0, _irq_1, _irq_2

_irq_0:
    call irq_horloge
    mov al, 0x20
    out 0x20, al
    iret

_irq_1:
    call irq_clavier
    mov al, 0x20
    out 0x20, al
    iret

_irq_2:
    call default_irq
    mov al, 0x20
    out 0x20, al
    iret
