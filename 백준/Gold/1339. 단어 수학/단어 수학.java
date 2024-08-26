import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Main {
    static String[] words;
    static int[] alphabetValues; // 알파벳의 숫자 값을 저장
    static Map<Character, Integer> letterImportance;

    static class Letter {
        char letter;
        int importance;

        Letter(char letter, int importance) {
            this.letter = letter;
            this.importance = importance;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        words = new String[N];
        letterImportance = new HashMap<>();

        for (int i = 0; i < N; i++) {
            words[i] = br.readLine();
            calculateImportance(words[i]);
        }

        PriorityQueue<Letter> pq = new PriorityQueue<>((a, b) -> b.importance - a.importance);
        for (Map.Entry<Character, Integer> entry : letterImportance.entrySet()) {
            pq.add(new Letter(entry.getKey(), entry.getValue()));
        }

        alphabetValues = new int[26];
        int num = 9;
        while (!pq.isEmpty()) {
            Letter letter = pq.poll();
            alphabetValues[letter.letter - 'A'] = num--;
        }

        int answer = 0;
        for (String word : words) {
            answer += convertToNumber(word);
        }

        System.out.println(answer);
        br.close();
    }

    static void calculateImportance(String word) {
        int length = word.length();
        int factor = 1;
        for (int i = length - 1; i >= 0; i--) {
            char c = word.charAt(i);
            letterImportance.put(c, letterImportance.getOrDefault(c, 0) + factor);
            factor *= 10;
        }
    }

    static int convertToNumber(String word) {
        int number = 0;
        for (char c : word.toCharArray()) {
            number = number * 10 + alphabetValues[c - 'A'];
        }
        return number;
    }
}
