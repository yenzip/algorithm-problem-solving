import java.io.*;
import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        PriorityQueue<Integer> minPQ = new PriorityQueue<>();   // 최소힙
        PriorityQueue<Integer> maxPQ = new PriorityQueue<>(Collections.reverseOrder()); // 최대힙
        int size = 0;
        
        for(String op : operations) {
            char cmd = op.charAt(0);
            int val = Integer.parseInt(op.substring(2));
            
            if(cmd == 'I') {    // 삽입
                minPQ.offer(val);
                maxPQ.offer(val);
                size++;
            } else {            // 삭제
                if(size == 0) {
                    continue;
                }
                
                if(val == 1) {
                    maxPQ.poll();
                } else {
                    minPQ.poll();
                }
                
                size--;
            }
            
            if(size == 0) {
                minPQ.clear();
                maxPQ.clear();
            }
        }
        
        return (size == 0 ? new int[]{0, 0} : new int[]{maxPQ.peek(), minPQ.peek()});

    }
}