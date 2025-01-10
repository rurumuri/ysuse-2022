.model small
.stack 100h

.data
    var db 53H
    message db '?','$'

.code
main proc
    mov ax, @data
    mov ds, ax

    mov message, 4CH
    mov al, var
    mov bl, al

    shl al, 1
    JC done

    mov message, 52H
    shr bl, 1
    JC done

    mov message, 4DH

done:
    mov dx, offset message
    mov ah, 9
    int 21H

    mov ah, 4Ch
    xor al, al
    int 21h
main endp

end main
