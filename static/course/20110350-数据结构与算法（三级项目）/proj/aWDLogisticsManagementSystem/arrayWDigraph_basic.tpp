

// 构造函数，接受初始节点个数作为参数
template<class T>
arrayWDigraph<T>::arrayWDigraph(int n_vertex_primary){
    // 检查初始化参数是否合法
    while(true){
        if(n_vertex_primary < 0){
            cout << "Bad n_vertex input! Try again." << endl << "> ";
            cin >> n_vertex_primary;
        }else{
            break;
        }
    }
    // 初始化图的属性
    n_vertex = n_vertex_primary;
    n_edge = 0;
    V = vector<NodeInfo>(n_vertex + 1); // 注：下标从1开始
    G = vector<Vertex>{ (const unsigned __int64)(n_vertex + 1), Vertex() };
    vis = new int[n_vertex + 1];
    path_floyd = NULL;
    dis_floyd = NULL;
    path_dijkstra = NULL;
    dis_dijkstra = NULL;
    is_reachable = NULL;
}

// 根据NodeInfo的node_id编号（人类可读）获取V<NodeInfo>中对应的索引（即对应到V的存储结构）
template<class T>
int arrayWDigraph<T>::getIndex(int x) {
    for (int i = 1; i <= n_vertex; i++){
        if (V[i].node_id == x){
            return i;
        }
    }
}

template<class T>
bool arrayWDigraph<T>::existsEdge(int vertex_in_id, int vertex_out_id) const {
    int c = G[vertex_in_id].conn_vertices.size();
    for (int i = 0; i < c; i++){
        if (G[vertex_in_id].conn_vertices[i].node_id == vertex_out_id){
            return true;
        }
    }
    return false;
}

template<class T>
bool arrayWDigraph<T>::existVertex(int node_id){
    for (int i = 0; i < V.size(); i++){
        if (node_id == V[i].node_id){
            return true;
        }
    }
    return false;
}

template<class T>
bool arrayWDigraph<T>::isEdgeLegal(int v1, int v2){
    if (v1 < 1 || v2 < 1){
        return false;
    }else{
        return true;
    }
}

template<class T>
bool arrayWDigraph<T>::isVertexLegal(int node_id) {
    if (node_id >= 1){
        return true;
    }
    else{
        cout << "Illegal n_vertex!" << endl;
        return false;
    }
}

template<class T>
bool arrayWDigraph<T>::isWeightLegal(T weight) {
    if (weight < 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// 插入边 首先检查边是否合法（即端点是否合法）【注意：默认两个端点均存在，没有检查？？】
template<class T>
void arrayWDigraph<T>::insertEdge(edge<T>* Edge) {
    // 获取并检查
    int v1 = Edge->get_vertex_in_id();
    int v2 = Edge->get_vertex_out_id();
    T w = Edge->get_weight();
    if (!isEdgeLegal(v1, v2)) return;

    // 若存在边则更新权值，否则创建边
    int v = getIndex(v1);
    if (existsEdge(getIndex(v1), v2)){
        auto p = G[v].conn_vertices.begin();
        for (auto i = G[v].conn_vertices.begin(); i < G[v].conn_vertices.end(); i++)
            if ((*i).node_id == v2)
                p = i;
        p->node_weight = w;
    }else{
        V[getIndex(v2)].in_degree++;
        V[v].out_degree++;
        G[v].conn_vertices.push_back(Node<T>(v2, w));
        n_edge++;
    }
}

template<class T>
bool arrayWDigraph<T>::eraseEdge(int v1, int v2) {
    int v = getIndex(v1);
    if (!isEdgeLegal(v1, v2)){
        return false;
    }
    if (!existsEdge(getIndex(v1), v2)){
        return false;
    }
    for (auto i = G[v].conn_vertices.begin(); i != G[v].conn_vertices.end(); i++){
        if ((*i).node_id == v2){
            // G[v].conn_vertices.erase(remove(G[v].conn_vertices.begin(), G[v].conn_vertices.end(), vertex_out), G[v].conn_vertices.end());
            G[v].conn_vertices.erase(i);
            V[v].out_degree--;
            V[v].in_degree--;
            n_edge--;
            break;
        }
    }
    return true;
}

//更新权值
template<class T>
void arrayWDigraph<T>::updateWeight(int vertex_in_id, int vertex_out_id, T new_weight) {
    int c = G[getIndex(vertex_in_id)].conn_vertices.size();
    for (int i = 0; i < c; i++)
    {
        if (G[getIndex(vertex_in_id)].conn_vertices[i].node_id == vertex_out_id)
        {
            G[getIndex(vertex_in_id)].conn_vertices[i].node_weight = new_weight;
        }
    }
    cout << "Update successful. " << endl;
    int a;
    cout << "Enter 0 to exit, 1 to continue. " << endl << "> ";
    cin >> a;
    switch (a) {
        case 1:
            addEdge(); break;
        case 0:return;
    }
}

// 增加点
template<class T>
void arrayWDigraph<T>::addVertexSingle(int node_id, string node_info_name) {
    // 更新V（末尾增加）（因此节点自身id不同于节点在存储结构中的位置！！！这是getIndex函数的价值所在）
    NodeInfo node(node_id, node_info_name);
    V.push_back(node);
    // 更新G（末尾增加）
    Vertex new_node;
    new_node.node_id = node_id;
    new_node.conn_vertices.clear();
    G.push_back(new_node);
    // 更新图信息
    n_vertex++;
}

// 删除点
template<class T>
void arrayWDigraph<T>::deleteVertexSingle(int node_id) {
    int x = getIndex(node_id);
    int num = G[x].conn_vertices.size();
    G.erase(G.begin() + x, G.begin() + x + 1);
    n_edge -= num;
    V.erase(V.begin() + x, V.begin() + x + 1);
    n_vertex--;
    for (int i = 1; i < G.size(); i++){
        for (int j = 0; j < G[i].conn_vertices.size(); j++){
            if (G[i].conn_vertices[j].node_id == node_id){
                G[i].conn_vertices.erase(G[i].conn_vertices.begin() + j, G[i].conn_vertices.begin() + j + 1);
                V[i].out_degree--;
            }
        }
    }
}

// 添加地点
template<class T>
void arrayWDigraph<T>::addVertex(){
    system("cls");
    cout << "=======Add Vertex=======" << endl;
    int n;
    cout << "Enter the number of new vertices.\n> ";
    cin >> n;
    int x;
    string y;
    for (int i = 0; i < n; i++){
        cout << "Enter the node_id" << endl;
        while (1){
            cout<<"> ";
            cin >> x;
            if (!isVertexLegal(x)){
                cout << "Bad node_id, try again!\n> ";
                continue;
            }else if (existVertex(x)){
                cout << "Node exists. ";
                cout << "Try again: \n> ";
                continue;
            }break;
        }
        cout << "Enter the name of the node. \n> ";
        cin >> y;

        addVertexSingle(x, y);
        addVertexFile(x, y);
        cout << "Node " << x << " added successful. " << endl << endl;
    }
    int a;
    cout << "Enter 0 to exit, 1 to continue. " << endl;
    cout<<"> ";
    cin >> a;
    switch (a) {
        case 1:
            addVertex(); break;
        case 0:
            return;
    }
}

// 添加地点重载函数
template<class T>
void arrayWDigraph<T>::addVertex(int x)
{
    string y;
    //int o;
    cout << "Enter the name of the node:\n> ";
    cin >> y;
    addVertexSingle(x, y/*, o*/);
    addVertexFile(x, y);
    cout << "Node " << x << " added successful. " << endl << endl;

}
// 删除地点
template<class T>
void arrayWDigraph<T>::deleteVertex(){
    system("cls");
    if (n_vertex == 0){
        cout << "No node exists! " << endl;
        system("pause");
        return;
    }
    else{
        cout << "=======Delete Vertex=======" << endl;
        int n;
        cout << "Enter the number of vertices:\n> ";
        cin >> n;
        int x;
        for (int i = 0; i < n; i++){
            cout << "Enter the node_id of vertices:\n> ";
            cin >> x;
            deleteVertexSingle(x);
            deleteVertexFile(x);
            cout << "Node " << x << " delete successful." << endl << endl;
        }
        int a;
        cout << "Enter 0 to exit, 1 to continue. " << endl << "> ";
        cin >> a;
        switch (a) {
            case 1:
                deleteVertex(); break;
            case 0:
                return;
        }
    }
}

// 添加路
template<class T>
void arrayWDigraph<T>::addEdge()
{
    system("cls");
    cout << "=======Add Edge=======" << endl;
    int n;
    cout << "Enter the number of the edges:\n> ";
    cin >> n;
    int x, y;
    T w;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the start node_id:\n> ";
        while (1) {
            cin >> x;
            if (isVertexLegal(x)){
                break;
            }
            else {
                cout << "Bad input. Try again. \n> " << endl;
            }
        }
        if (!existVertex(x))
        {
            int p;
            cout << "Not exist node " << x << ". Add node " << x << "?" << endl;
            cout << "Enter 2 to exit, 1 to continue. \n> " << endl;
            cin >> p;
            switch (p) {
                case 1:
                    this->addVertex(x); break;
                case 2:return;
            }
        }
        cout << "Enter the end node_id: \n> ";
        while (1) {
            cin >> y;
            if (isVertexLegal(y)){
                break;
            }
            else {
                cout << "Bad input. Try again.\n> " << endl;
            }
        }
        if (!existVertex(y)){
            int p;
            cout << "Not exist node " << y << ". Add node " << y << "?" << endl;
            cout << "Enter 2 to exit, 1 to continue" << endl << "> ";
            cin >> p;
            switch (p) {
                case 1:
                    this->addVertex(y); break;
                case 2:return;
            }
        }
        if (existsEdge(getIndex(x), y)) {
            cout << "Edge exists. Still update the weight? \nEnter 0 to exit, 1 to continue." << endl;
            int p;
            cout<<"> ";
            cin >> p;
            switch (p)
            {
                case 0:
                    return;
                case 1: {cout << "Input the weight of the edge: ";
                    while (1)
                    {
                        cout<<"> ";
                        cin >> w;
                        if (isWeightLegal(w)){
                            break;
                        }
                        else{
                            cout << "Bad weight. Try again." << endl;
                        }
                    }
                    updateWeight(x, y, w);
                    return; }
            }
        }
        cout << "Input the weight of the edge: "<<endl;
        while (1)
        {
            cout<<"> ";
            cin >> w;
            if (isWeightLegal(w))
            {
                break;
            }
            else
            {
                cout << "Bad weight. Try again." << endl;
            }
        }
        edge<T>* ed = new edge<T>(x, y, w);
        insertEdge(ed);
        addEdgeFile(x, y, w);
        cout << "Edge"; ed->output(); cout << " Added successful. " << endl << endl;
    }
    int a;
    cout << "Enter 0 to exit, 1 to continue" << endl;
    cout<<"> ";
    cin >> a;
    switch (a) {
        case 0:return;
        case 1:
            addEdge(); break;
    }
}

// 删除边
template<class T>
void arrayWDigraph<T>::deleteEdge()
{
    system("cls");
    if (n_edge == 0)
    {
        cout << "No edge exists" << endl;
        system("pause");
        return;
    }
    cout << "=======Delete Edge=======" << endl;
    int n;
    cout << "Enter the number of edges to delete: "<<endl;
    cout<<"> ";
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the start node_id: "<<endl;
        while (1) {
            cout<<"> ";
            cin >> x;
            if (!existVertex(x)){
                cout << "Not exist node: " << x << endl;
                cout << "Try again: ";
            }
            else{
                break;
            }
        }
        cout << "Enter the end node_id: "<<endl;
        while (true) {
            cout<<"> ";
            cin >> y;
            if (!existVertex(y)){
                cout << "Not exist node: " << y << endl;
                cout << "Try again: ";
            }
            else{
                break;
            }
        }
        if (existsEdge(getIndex(x), y)){
            eraseEdge(x, y);
            deleteEdgeFile(x, y);
        }
        cout << "Edge (" << x << ", " << y << ") deleted successful" << endl << endl;
        system("pause");
    }
}


// 连通集
template<class T>
void arrayWDigraph<T>::connectedSets() {
    system("cls");
    cout<<"=======Connected Sets======="<<endl;
    vis = new int[n_vertex + 1];
    fill(vis, vis + n_vertex + 1, 0);
    int a, b;
    b = 0;
    vector<vector<int>> lian;
    stack<int> sl;
    vector<int> du;
    lian.clear();
    b = 0;
    for (int i = 1; i <= n_vertex; i++) {
        if (vis[i] == 0) {
            sl.push(i);
            du.push_back(i);
            vis[i] = 1;
        }
        while (!sl.empty()) {
            a = sl.top();
            sl.pop();
            for (int j = 0; j < G[a].conn_vertices.size(); j++) {
                int re = getIndex(G[a].conn_vertices[j].node_id);
                if (vis[re] == 0) {
                    sl.push(re);
                    du.push_back(re);
                    vis[re] = 1;
                }
            }
        }
        if (!du.empty()) {
            lian.push_back(du);
            b++;
            du.clear();
        }
    }
    if (!lian.empty()) {
        cout << "connectedSets set: " << endl;
        for (int i = 0; i < b; i++) {
            int x = 0;
            cout << "The " << i + 1 << " part: ";
            while (x < lian[i].size()) {
                cout << V[lian[i][x++]].node_id << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cout << "No result!" << endl;
    }
    system("pause");
}


template<class T>
void arrayWDigraph<T>::outputG(){
    system("cls");
    cout<<"=======Output All Edges======="<<endl;
    if (n_vertex == 0){
        cout << "Error: The graph is empty! " << endl;
        system("pause");
        return;
    }
    for(const auto& i : G){
        for(auto j : i.conn_vertices){
            cout << i.node_id <<" "<< j.node_id <<" "<< j.node_weight << endl;
        }
    }
    cout<<"=============================="<<endl;
    system("pause");
}


template<class T>
void arrayWDigraph<T>::outputV(){
    system("cls");
    cout<<"=======Output All Nodes======="<<endl;
    if (n_vertex == 0){
        cout << "Error: The graph is empty! " << endl;
        system("pause");
        return;
    }
    for(const auto& i : V){
        if(i.node_id != 0) cout << "node_id: " << i.node_id << " name: " << i.name << " in_degree: " << i.in_degree << " out_degree: " << i.out_degree << endl;
    }
    cout<<"=============================="<<endl;
    system("pause");
}