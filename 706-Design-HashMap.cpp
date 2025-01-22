class MyHashMap {
public:
    int arr[751][829];
    int sz1 = 751, sz2 = 829;
    MyHashMap() {
        memset(arr,-1,sizeof(arr));
    }

    void put(int key, int value) {
        int i = key % sz1, j = key % sz2;
        arr[i][j] = value;
    }

    int get(int key) {
        int i = key % sz1, j = key % sz2;
        return arr[i][j];
    }

    void remove(int key) {
        int i = key % sz1, j = key % sz2;
        arr[i][j] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */