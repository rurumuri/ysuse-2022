CRLF         MACRO
MOV         AH, 02H
MOV         DL, 0DH
INT         21H
MOV         AH, 02H
MOV         DL, 0AH
INT         21H
ENDM

DATA        SEGMENT
STUNUM     EQU       10
MESS        DB        ' INPUT 10 STUDENTS SCORE: ',0DH,0AH,'$'
ERROR       DB        ' INPUT ERROR! PLEASE TRY AGAIN.',0DH,0AH,'$'
ORG         1000H
SCORE       DB        10 DUP (?)
ORG         2000H
SEQU        DB        10 DUP (?)
DATA        ENDS

STACK      SEGMENT
STA         DW         12 DUP (?)
TOP         DW         ?
STACK      ENDS

CODE       SEGMENT
ASSUME    CS:CODE,DS:DATA,ES:DATA,SS:STACK

START:      MOV       AX, DATA
            MOV       DS, AX
            MOV       ES, AX
            MOV       SP, TOP            ; 初始化栈
            MOV       AH, 09H
            MOV       DX, OFFSET MESS
            INT       21H                ; 显示提示信息
            MOV       SI, OFFSET SCORE    ; 成绩表首址
            MOV       CX, STUNUM          ; 学生数送CX

INPUT_SCORES:
            CALL      GETNUM              ; 读取键入数值送DX
            MOV       [SI], DL            ; 存入成绩表缓冲区
            INC       SI                  ; 指向下一单元
            LOOP      INPUT_SCORES

            MOV       CX, STUNUM          ; 学生数
            MOV       DI, OFFSET SEQU      ; 名次表首址

CALCULATE_RANKS:
            CALL      SCAN                ; 扫描子程序
            MOV       AL, STUNUM          ; 学生数
            SUB       AL, CL
            INC       AL                  ; 计算名次
            MOV       BX, DX 
            MOV       [DI + BX], AL       ; 记DX学号对应名次
            LOOP      CALCULATE_RANKS

            MOV       CX, STUNUM          ; 学生数
            MOV       SI, OFFSET SEQU      ; 名次表首址

DISPLAY_RANKS:
            MOV       AL, [SI]
            CALL      DISP1
            CRLF
            INC       SI
            LOOP      DISPLAY_RANKS        ; 显示排定的学生名次

            MOV       AX, 4C00H
            INT       21H

SCAN   PROC      NEAR             
    PUSH    CX
    MOV     CX, STUNUM             ; 学生数
    MOV     AL, 0                   ; 初始化最低成绩
    MOV     BX, OFFSET SCORE
    MOV     SI, BX                  ; 指向成绩表首址

FIND_HIGHEST:
    CMP     AL, [SI]
    JAE     NEXT_SCORE               ; 如果AL中的成绩不低于当前成绩则跳转
    MOV     AL, [SI]                 ; 更新AL为较高的成绩
    MOV     DX, SI 
    SUB     DX, BX                   ; DX为对应学号

NEXT_SCORE:
    INC     SI                       ; 指向下一单元
    LOOP    FIND_HIGHEST

    ADD     BX, DX
    MOV     BYTE PTR[BX], 0H        ; 本次扫描成绩最高者清0          
    POP     CX
    RET
SCAN       ENDP

DISP1       PROC     NEAR
    PUSH     CX
    MOV      BL, AL
    MOV      DL, BL
    MOV      CL, 04
    ROL      DL, CL
    AND      DL, 0FH
    CALL     DISPL
    MOV      DL, BL
    AND      DL, 0FH
    CALL     DISPL
    POP      CX
    RET
DISP1       ENDP

DISPL       PROC    NEAR
    ADD      DL, 30H
    CMP      DL, 3AH
    JB       DISPLAY_CHAR
    ADD      DL, 27H
DISPLAY_CHAR:
    MOV      AH, 02H
    INT      21H
    RET
DISPL      ENDP                    

GETNUM   PROC    NEAR
    PUSH      CX
    XOR       DX, DX

READ_CHAR:
    MOV      AH, 01H
    INT      21H
    CMP      AL, 0DH
    JZ       RETURN_NUM
    CMP      AL, 20H
    JZ       RETURN_NUM
    SUB      AL, 30H
    JB       INVALID_INPUT
    CMP      AL, 0AH
    JB       STORE_NUM
    CMP      AL, 11H
    JB       INVALID_INPUT
    SUB      AL, 07H
    CMP      AL, 0FH
    JBE      STORE_NUM
    CMP      AL, 2AH
    JB       INVALID_INPUT
    CMP      AL, 2FH
    JA       INVALID_INPUT
    SUB      AL, 20H

STORE_NUM:
    MOV     CL, 04
    SHL     DX, CL
    XOR     AH, AH
    ADD     DX, AX
    JMP     READ_CHAR

INVALID_INPUT:
    MOV      AH, 09H
    MOV      DX, OFFSET ERROR
    INT      21H
    JMP     READ_CHAR

RETURN_NUM:
    PUSH      DX 
    CRLF
    POP       DX
    POP       CX
    RET
GETNUM   ENDP                   

CODE      ENDS
END       START
