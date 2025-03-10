
// 字符串转换为模板类参数T
template<class T>
T arrayWDigraph<T>::stringToT(const string& str){
    istringstream iss(str);
    T num;
    iss >> num;
    return num;
}

// 将文件一行的字符串切割
template<class T>
string arrayWDigraph<T>::getFirstPart(string s) {
    string f;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ' '){
            f = s.substr(0, i + 1);
            break;
        }
    }
    return f;
}

// 同上
template<class T>
string arrayWDigraph<T>::getSecondPart(string s) {
    string f;
    bool flag = false;
    int x;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ' ' && !flag){
            flag = true;
            x = i;
        }
        else{
            if (s[i] == ' ' && flag){
                f = s.substr(x + 1, i - x);
                break;
            }
        }
    }
    return f;
}

// 同上
template<class T>
string arrayWDigraph<T>::getThirdPart(string s) {
    string f;
    bool flag = false;
    int x;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ' ' && !flag){
            flag = true;
            x = i;
        }else{
            if (s[i] == ' ' && flag){
                f = s.substr(i + 1, s.size() - i - 1);
                break;
            }
        }
    }
    return f;
}

// 返回第一个空格位置的字符串索引
template<class T>
int arrayWDigraph<T>::locateFirstBlank(string s) {
    int x;
    for (int i = 0; i < s.size(); i++){ // 第一次找空格
        if (s[i] == ' '){
            x = i;
            break;
        }
    }
    return x;
}

// 返回第二个空格位置的字符串索引
template<class T>
int arrayWDigraph<T>::locateSecondBlank(string s) {
    int x;
    bool flag = false; // 第一次找到空格
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ' ' && !flag){
            flag = true;
        }
        else{
            if (s[i] == ' ' && flag){ // 第二次继续找空格
                x = i;
                break;
            }
        }
    }
    return x;
}

// 在文件中更新权值
template<class T>
void arrayWDigraph<T>::updateEdgeWeight(int x, int y, T z) {
    vector<string>vf;
    string s;
    fstream outfile;
    outfile.open("../edges.txt");
    while (!outfile.eof()){
        getline(outfile, s);
        if (stoi(getFirstPart(s)) == x && stoi(getSecondPart(s)) == y){
            s = s.substr(0, locateSecondBlank(s));
            string c = to_string(z);
            s += c;
            vf.push_back(s);
        }
        else{
            if (s != ""){
                vf.push_back(s);
            }
        }
    }
    outfile.close();
    ofstream out("../edges.txt");
    out.close();
    outfile.open("../edges.txt", ios::app);
    for(const auto & i : vf){
        outfile << i << endl;
    }
    outfile.close();
}


// 在文件中写入点x
template<class T>
void arrayWDigraph<T>::addVertexFile(int x, string y) {
    ofstream outfile;
    outfile.open("../vertex.txt", ios::app);
    outfile << x << " " << y << endl;
    outfile.close();
}


// 删除点的文件操作
template<class T>
void arrayWDigraph<T>::deleteVertexFile(int x) {
    vector<string> vf;
    string s;
    fstream outfile;
    outfile.open("../vertex.txt");
    while (!outfile.eof()){
        getline(outfile, s);
        if (atoi(getFirstPart(s).c_str()) != x && !s.empty()){
            vf.push_back(s);
        }
    }
    outfile.close();
    ofstream out("../vertex.txt");
    out.close();
    outfile.open("../vertex.txt", ios::app);
    for (const auto & i : vf){
        outfile << i << endl;
    }
    outfile.close();
    vf.clear();
    outfile.open("../edges.txt");
    while (!outfile.eof()){
        getline(outfile, s);
        if (s != ""){
            if (atoi(getFirstPart(s).c_str()) != x && atoi(getSecondPart(s).c_str()) != x){

                vf.push_back(s);
            }
        }
    }
    outfile.close();
    ofstream out1("../edges.txt");
    out1.close();
    outfile.open("../edges.txt", ios::app);
    for (const auto & i : vf){
        outfile << i << endl;
    }
    outfile.close();
}


// 在文件中写入边x->y
template<class T>
void arrayWDigraph<T>::addEdgeFile(int x, int y, T z) {
    ofstream outfile;
    outfile.open("../edges.txt", ios::app);
    outfile << x << " " << y << " " << z << endl;
    outfile.close();
}


// 删除路的文件操作，相当于从头到尾除了目标边均复制到临时向量edge_tmp，最后再复制回去
template<class T>
void arrayWDigraph<T>::deleteEdgeFile(int x, int y) {
    vector<string> edge_tmp;
    string s;
    fstream outfile;
    outfile.open("../edges.txt");
    while (!outfile.eof()){
        getline(outfile, s);
        if (!s.empty()){
            if (stoi(getFirstPart(s).c_str()) != x || stoi(getSecondPart(s).c_str()) != y){
                edge_tmp.push_back(s);
            }
        }
    }
    outfile.close();

    ofstream out("../edges.txt");
    out.close();
    //outfile.open("../edge.txt", ios::app);
    outfile.open("../edges.txt", ios::app); // 曾在此处发现bug
    for(const auto & i : edge_tmp){
        outfile << i << endl;
    }
    outfile.close();
}

//文件清空
template<class T>
void arrayWDigraph<T>::clearAllFiles(){
    system("cls");
    cout << "=======Clear All Files=======" << endl;
    ofstream fileStream1("../edges.txt", ofstream::out | ofstream::trunc);
    fileStream1.close();
    ofstream fileStream2("../vertex.txt", ofstream::out | ofstream::trunc);
    fileStream2.close();
    ofstream fileStream3("../edges2.txt", ofstream::out | ofstream::trunc);
    fileStream1.close();
    ofstream fileStream4("../vertex2.txt", ofstream::out | ofstream::trunc);
    fileStream2.close();
    cout<<"OK!"<<endl<<endl;
    system("pause");
}
