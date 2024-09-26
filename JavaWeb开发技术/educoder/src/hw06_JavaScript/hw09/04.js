function mainJs(a, b) {
    let curpos = 0;
    let result = '';

    while (true) {
        curpos = a.indexOf(b, curpos);
        if (curpos === -1) {
            break;
        } else {
            result += a.slice(0, curpos); // 添加b之前的字符
            result += b.toUpperCase(); // 添加大写的b
            a = a.slice(curpos + b.length); // 更新a，移除已处理的部分
            curpos = 0; // 重置curpos，因为我们已经更新了a
        }
    }

    result += a; // 添加剩余的a

    return result;
}
