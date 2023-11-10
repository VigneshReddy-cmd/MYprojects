import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

 class Mymatrix {
    public static void main(String[] args) {
        char[][] matrix = {
            {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
            {'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'},
            {'q', 'r', 's', 't', 'u', 'v', 'w', 'x'},
            {'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f'},
            {'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
            {'o', 'p', 'q', 'r', 's', 't', 'u', 'v'},
            {'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd'},
            {'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'}
        };

        char[][] rearrangedMatrix = rearrangeMatrix(matrix);

        if (rearrangedMatrix != null) {
            for (char[] row : rearrangedMatrix) {
                for (char c : row) {
                    System.out.print(c + " ");
                }
                System.out.println();
            }
        }
    }

    public static char[][] rearrangeMatrix(char[][] matrix) {
        int vowelCount = 0;
        int consonantCount = 0;
        List<Character> vowels = new ArrayList<>();
        List<Character> consonants = new ArrayList<>();

        // Collect vowels and consonants, and replace edges with vowels
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                char currentChar = matrix[row][col];
                if (Character.isLetter(currentChar)) {
                    if ("aeiouAEIOU".contains(String.valueOf(currentChar))) {
                        vowelCount++;
                        vowels.add(currentChar);
                    } else {
                        consonantCount++;
                        consonants.add(currentChar);
                    }

                    // Replace edges with vowels
                    if (row == 0 || row == 7 || col == 0 || col == 7) {
                        matrix[row][col] = 'a';
                    }
                }
            }
        }

        // Check if the counts of vowels and consonants are the same
        if (vowelCount != consonantCount) {
            System.out.println("The counts of vowels and consonants are not the same.");
            return null;
        }

        // Shuffle the vowels and consonants lists randomly
        Collections.shuffle(vowels, new Random(42));
        Collections.shuffle(consonants, new Random(42));

        char[][] rearrangedMatrix = new char[8][8];
        int vowelIndex = 0;
        int consonantIndex = 0;

        // Rearrange the matrix while keeping counts the same
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                char currentChar = matrix[row][col];
                if (Character.isLetter(currentChar)) {
                    if ("aeiouAEIOU".contains(String.valueOf(currentChar))) {
                        rearrangedMatrix[row][col] = vowels.get(vowelIndex++);
                    } else {
                        rearrangedMatrix[row][col] = consonants.get(consonantIndex++);
                    }
                } else {
                    rearrangedMatrix[row][col] = currentChar; // Non-alphabet characters remain unchanged
                }
            }
        }

        return rearrangedMatrix;
    }
}
