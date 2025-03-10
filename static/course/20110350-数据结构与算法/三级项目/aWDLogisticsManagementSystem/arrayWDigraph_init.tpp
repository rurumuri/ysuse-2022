
// 使用文件vertex.txt和edges.txt初始化
template<class T>
void arrayWDigraph<T>::autoInitFromFile1() {
    system("cls");
    cout << "=======Auto Initialization=======" << endl;
    if (n_vertex != 0)
    {
        cout << "Graph is not empty. Initialization paused. " << endl;
        cout << "Are you sure to clear the graph? Enter 1 for yes and 0 for not. " << endl;
        int a;
        cout<<"> ";
        cin >> a;
        switch (a){
            case 1:
                clearProgramData(); break;
            case 0:return;
        }
    }
    system("cls");
    cout << "=======Auto Initialization=======" << endl;
    cout << "Auto initializing" << endl;
    fstream outfile;
    outfile.open("../vertex.txt");
    string s;
    int x, y;//, z;
    string na;
    while (!outfile.eof()){
        getline(outfile, s);
        if (s != ""){
            x = atoi(getFirstPart(s).c_str());
            na = getSecondPart(s);
            //z = atoi(getThirdPart(s).c_str());
            addVertexSingle(x, na /*, z*/);
        }
    }
    outfile.close();
    fstream out;
    out.open("../edges.txt");
    string c;
    while (!out.eof()){
        getline(out, s);
        if (s != ""){
            x = atoi(getFirstPart(s).c_str());
            y = atoi(getSecondPart(s).c_str());
            c = getThirdPart(s);
            T p = stringToT(c);
            edge<T>* ed = new edge<T>(x, y, p);
            insertEdge(ed);
        }
    }
    out.close();
    system("cls");
    cout << "=======Auto Initialization=======" << endl;
    cout << "Initialized successful. " << endl;
    system("pause");
}

// 使用xxx2文件初始化
template<class T>
void arrayWDigraph<T>::autoInitFromFile2() {
    system("cls");
    cout<<"=======Auto Initialization======="<<endl;
    if (n_vertex != 0){
        cout << "Graph is not empty. Are you still sure to initialize?" << endl;
        cout << "Enter 1 to init, 0 to quit." << endl;
        int a;
        cout<<"> ";
        cin >> a;
        switch(a){
            case 1:
                clearProgramData(); break;
            case 0:
                return;
        }
    }
    system("cls");
    cout << "Auto initializing" << endl;
    ifstream outfile;
    outfile.open("../vertex2.txt");

    if(!outfile.is_open()){
        cout<<"Can't read file. "<<endl;
    }

    string s, na;
    int x, y/*, z*/;
    while (getline(outfile, s)){

        if (s != ""){
            x = stoi(getFirstPart(s).c_str());
            na = getSecondPart(s);
            //z = atoi(getThirdPart(s).c_str());
            addVertexSingle(x, na/*, z*/);
        }
    }
    outfile.close();
    fstream out;
    out.open("../edges2.txt");
    string c;
    while (!out.eof()){
        getline(out, s);
        if (s != ""){
            x = atoi(getFirstPart(s).c_str());
            y = atoi(getSecondPart(s).c_str());
            c = getThirdPart(s);
            T p = stringToT(c);
            edge<T>* ed = new edge<T>(x, y, p);
            insertEdge(ed);
        }
    }
    out.close();
    system("cls");
    cout << "=======Auto Initialization=======" << endl;
    cout << "Initialized successful" << endl;
    system("pause");
}


// 初始化操作界面
template<class T>
void arrayWDigraph<T>::init() {
    bool flag = false;
    while (1) {
        int a;
        if (flag) {
            break;
        }
        system("cls");
        cout << "==============aWDLogisticManagementSystem=============" << endl;
        //cout << "=====================arrayWDigraph====================" << endl;
        cout << endl;
        cout << "--------------Init--------------" << endl;
        cout << "1. Add sites" << endl;
        cout << "2. Add routes" << endl;
        cout << "3. Delete sites" << endl;
        cout << "4. Delete routes" << endl;
        cout << "5. Clear program data" << endl;
        cout << "6. Clear all files data" << endl;
        cout << "7. Init from file I" << endl;
        cout << "8. Init from file II" << endl;
        cout << endl;
        cout << "------------Utilities-----------" << endl;
        cout << "9. Output all vertices" << endl;
        cout << "10. Output all edges" << endl;
        cout << "11. Get all connected sets" << endl;
        cout << "12. Site topo-arrangement" << endl;
        cout << "13. Shortest path (single)" << endl;
        cout << "14. Shortest path (all)" << endl;
        cout << "15. Shortest path (single, A*)" << endl;
        cout << "16. Shortest path via somewhere" << endl;
        cout << "17. DFS performance test" << endl;
        cout << "18. Quit" << endl;

        cout << endl;
        cout << "ATTENTION: All operations expect 'Clear program data' will SYNC to the file 'vertex.txt' and 'edges.txt'. " << endl;
        cout << "======================================================" << endl << endl;
        cout << "Enter the index of the operation:" << endl;
        cout<<"> "; cin >> a;
        switch (a) {
            case 1:
                addVertex();
                break;
            case 2:
                addEdge();
                break;
            case 3:
                deleteVertex();
                break;
            case 4:
                deleteEdge();
                break;
            case 5:
                clearProgramData();
                break;
            case 6:
                clearAllFiles();
                break;
            case 7:
                autoInitFromFile1();
                break;
            case 8:
                autoInitFromFile2();
                break;
            case 9:
                outputV();
                break;
            case 10:
                outputG();
                break;
            case 11:
                connectedSets();
                break;
            case 12:
                topoRank();
                break;
            case 13:
                dijkstraGetPath();
                break;
            case 14:
                floydGetPath();
                break;
            case 15:
                AStarGetPath();
                break;
            case 16:
                shortPathVia();
                break;
            case 17:
                DFSPerformCompare();
                break;
            case 18:
                flag = true;
                break;

        }
    }
}

//清空图
template<class T>
void arrayWDigraph<T>::clearProgramData() {
    system("cls");
    cout << "=======Clear Graph=======" << endl;
    if (n_vertex == 0){
        cout << "Error: The graph is already empty! " << endl;
        system("pause");
        return;
    }
    system("cls");
    cout << "Clearing graph" << endl;
    G.clear();
    V.clear();
    n_vertex = 0;
    n_edge = 0;
    vis = new int[n_vertex + 1];
    V = vector<NodeInfo>(n_vertex + 1);
    path_floyd = NULL;
    dis_floyd = NULL;
    path_dijkstra = NULL;
    dis_dijkstra = NULL;
    is_reachable = NULL;
    G = vector<Vertex>{(unsigned int)(n_vertex + 1), Vertex() };
    system("cls");
    cout << "OK!" << endl;
    system("pause");
}