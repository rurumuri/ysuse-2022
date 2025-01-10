.model small
.stack
.data
msg db 'please input string:$'
cmsg db 'please input char:$'
num db '? piece','$'  ; 定义占用的字节数，自动获取字符个数，一共多少字符
datamsg DB 7
        DB ?
        DB 7 DUP(?)
format db 0DH,0AH,'$'

.code
Main proc
    ; 提示输入字符
    MOV DX, offset msg
    mov ah, 9
    int 21H
    
    ; 字符串输入
    mov dx, offset datamsg
    mov ah, 0AH
    int 21H
    
    ; 回车
    mov dx, offset format
    mov ah, 9
    int 21H
    
    ; 输出
    mov dx, offset datamsg
    mov ah, 9
    int 21H
    
    ; 输入字符提示
    MOV DX, offset cmsg
    mov ah, 9
    int 21H
    
    ; 输入字符
    mov ah, 01H
    int 21H
    
    ; 回车
    mov dx, offset format
    mov ah, 9
    int 21H
    
    ; 初始化计数器
    xor bx, bx
    
    ; 循环次数
    mov cx, byte ptr [datamsg+1]
    
    ; 获取字符
    mov si, offset datamsg+2
    
    ; 循环比较
again:
    cmp al, [si]
    jnz next
    
    inc bl
    
next:
    inc si
    loop again
    
    ; 输出
    add bl, '0'  ; 将计数器的值转换为ASCII码
    mov num[0], bl
    mov dx, offset num
    mov ah, 9
    int 21H
    
    main endp
End main
