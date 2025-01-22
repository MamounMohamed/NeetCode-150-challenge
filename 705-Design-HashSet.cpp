class MyHashSet {
public:
    bool arr[1'000'001] = {};

    MyHashSet() {}

    void add(int key) { 
        if(!arr[key])
            arr[key]=1; 
        }

    void remove(int key) {
        if (arr[key])
            arr[key]=0;
    }

    bool contains(int key) { 
        return arr[key];
     }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */