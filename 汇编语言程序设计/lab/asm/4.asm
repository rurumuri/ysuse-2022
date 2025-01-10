mov bx, offset s5
		  mov cx, 6

printall:
		 ; 循环显示每个分数
		 push cx
		 mov ax, [bx]
		 call print_score
		 add bx, 2
		 pop cx
		 loop printall
		 
		 ; 换行
		 mov ah, 2
		 mov dl, 0DH				;  回车
		 int 21H
		 mov dl, 0AH				;  换行 
		 int 21H
		 
		 ret		;  返回主程序
		 
		 ;  打印ax中的成绩数字，放在栈里依次显示
print_score proc
		 push ax
		 push bx
		 push cx
		 push dx
		 
		 mov bx, 10
		 mov cx, 0
everynum:
		 xor dx, dx
		 div bx
		 push dx        ; 将余数压栈
		 inc cx
		 test ax, ax     ; 检查ax是否为0，不为0则表示不是最后一个数
		 jnz everynum
		 
show:
		 pop dx
		 add dl, '0'        ; 转化为ascll码
		 mov ah, 2
		 int 21h
		 
		  ; 换行
		 mov ah, 2
		 mov dl, 0DH				;  回车
		 int 21H
		 mov dl, 0AH				;  换行 
		 int 21H
		 
		 loop show
		 
		 pop dx
		 pop cx
		 pop bx
		 pop ax
		 
		 ret
print_score endp
