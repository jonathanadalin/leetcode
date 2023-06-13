class KthLargest {

// Category: Heap / Priority-queue
// Runtime: O(n log n) for instantiation & O(log n) for add

public:

    // Min priority-queue
    priority_queue<int, std::vector<int>, std::greater<int>> pq;  
    int pq_max_size;

    // O(n log n)
    KthLargest(int k, vector<int>& nums) {
        pq_max_size = k;
        for (int num : nums ) {
            add(num);
        }
    }
    
    // O(log n)
    int add(int val) {
        if (pq.size() < pq_max_size) {
            pq.push(val);
        } else {
            if (pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

