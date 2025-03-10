
// 教材DFS使用迭代器迭代
template<class T>
void arrayWDigraph<T>::rDFS(int start, int label){
    vis[start] = label;
    auto pointer = iterator(start);
    int now;
    while ((now = pointer->next()) != 0){
        if (vis[now] == 0)
            rDFS(now, label);
    }
    delete pointer;
}

// 定制DFS直接访问数据结构迭代
template<class T>
void arrayWDigraph<T>::sDFS(int start, int label){
    vis[start] = label;
    auto pointer = G[start].conn_vertices.begin();
    int now;
    while (pointer != G[start].conn_vertices.end()){
        now = pointer->node_id;
        if (vis[now] == 0)
            sDFS(now, label);
        pointer++;
    }
}

template<class T>
void arrayWDigraph<T>::customizedDFS(int start, int label){
    if (!isVertexLegal(start)) return;
    vis = new int[n_vertex + 1];
    fill(vis, vis + n_vertex + 1, 0);
    sDFS(start, label);
}

template<class T>
void arrayWDigraph<T>::DFS(int start, int label){
    if (!isVertexLegal(start))return;
    vis = new int[n_vertex + 1];
    fill(vis, vis + n_vertex + 1, 0);
    rDFS(start, label);
}

// 性能测试
template<class T>
void arrayWDigraph<T>::DFSPerformCompare(){
    //定制的
    system("cls");
    cout<<"=======DFS Test======="<<endl;
    if (n_vertex == 0)
    {
        cout << "Graph is not empty. Test aborted." << endl;
        system("pause");
        return;
    }
    system("cls");
    cout<<"=======DFS Test======="<<endl;
    cout << "Testing" << endl;

    // 自带DFS测试
    clock_t start1, finish1;
    int label = 1, count1 = 0;
    start1 = clock();
    do{
        DFS(1, label);
        count1++;
    } while (((finish1 = clock()) - start1) < 1000);
    double x1 = ((double)finish1 - (double)start1) / count1;

    // 定制DFS测试
    label = 1;
    int n = 0;
    clock_t start2, finish2;
    int count2 = 0;
    start2 = clock();
    do{
        customizedDFS(1, label);
        count2++;
    } while (((finish2 = clock()) - start2) < 1000);
    double x2 = ((double)finish2 - (double)start2) / count2;

    system("cls");
    cout<<"=======DFS Test======="<<endl;
    cout << "default DFS time:" << x1 << endl << "customized DFS time:" << x2 << endl;
    system("pause");
}
