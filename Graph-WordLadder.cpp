import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {

        Set<String> valid = new HashSet<>(wordList);
        if (!valid.contains(endWord)) return 0; // optimization

        Queue<String> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        q.offer(beginWord);
        visited.add(beginWord);

        int step = 1;

        while (!q.isEmpty()) {

            int size = q.size();
            for (int i = 0; i < size; i++) {

                String currWord = q.poll();

                if (currWord.equals(endWord)) return step;

                for (String nextWord : genSequence(currWord, valid)) {
                    if (!visited.contains(nextWord)) {
                        visited.add(nextWord);
                        q.offer(nextWord);
                    }
                }
            }
            step++;
        }

        return 0;
    }

    private List<String> genSequence(String word, Set<String> valid) {
        List<String> res = new ArrayList<>();
        char[] chars = word.toCharArray();

        for (int i = 0; i < chars.length; i++) {
            char original = chars[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original) continue;

                chars[i] = c;
                String newWord = new String(chars);
                if (valid.contains(newWord)) {
                    res.add(newWord);
                }
            }
            chars[i] = original;
        }

        return res;
    }
}
