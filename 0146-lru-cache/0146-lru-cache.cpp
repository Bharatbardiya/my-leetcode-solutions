class Node{
    public:
    int val;
    int key;
    Node*next, *prev;

    Node(int val, int key){
        this->val = val;
        this->key = key;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache {
    int cap;
    int size;
    Node* head, *tail;
    map<int, Node*>mp;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        this->size =0;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void erase(Node*curr){
        mp.erase(curr->key);
        Node*prev = curr->prev;
        Node*next = curr->next;
        prev->next = next;
        next->prev = prev;
        size--;
    }
    Node* append(int key, int val){
        Node*curr = new Node(val, key);
        Node*next = head->next;
        curr->prev = head;
        head->next = curr;
        next->prev = curr;
        curr->next = next;
        size++;
        return curr;
    }


    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node*curr = mp[key];
        int value = curr->val;
        erase(curr);
        mp[key] = append(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(size==cap){
                erase(tail->prev);
            }
            mp[key] = append(key, value);
        }
        else{
            Node*curr = mp[key];
            erase(curr);
            mp[key] = append(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */