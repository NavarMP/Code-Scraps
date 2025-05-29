#include <stdio.h>
#include <stdlib.h> // For exit() and malloc (though not used in final code, good practice)
#include <ctype.h>  // For isalpha(), isdigit()

#define MAX_EXPRESSION_LENGTH 256 // Increased MAX for longer expressions

// --- Utility Functions ---

/**
 * @brief Determines the precedence of an operator.
 *
 * Higher return values indicate higher precedence.
 * Parentheses are handled separately in the main logic.
 *
 * @param operator_char The character representing the operator.
 * @return An integer representing the precedence level:
 * 3 for '^' (exponentiation)
 * 2 for '*' and '/' (multiplication, division)
 * 1 for '+' and '-' (addition, subtraction)
 * 0 for any other character (e.g., operands, parentheses, or invalid).
 */
int getOperatorPrecedence(char operator_char) {
    if (operator_char == '^') {
        return 3;
    } else if (operator_char == '*' || operator_char == '/') {
        return 2;
    } else if (operator_char == '+' || operator_char == '-') {
        return 1;
    }
    return 0; // Lower precedence for non-operators or parentheses
}

/**
 * @brief Checks if a character is an operand (a letter or a digit).
 *
 * @param c The character to check.
 * @return 1 if the character is an operand, 0 otherwise.
 */
int isOperand(char c) {
    return isalpha(c) || isdigit(c);
}

// --- Core Conversion Function ---

/**
 * @brief Converts an infix expression to its equivalent postfix expression.
 *
 * This function implements the Shunting-Yard algorithm. It processes the
 * infix expression character by character, using a stack to manage operators
 * and parentheses, and building the postfix expression.
 *
 * @param infix A null-terminated string containing the infix expression.
 * @param postfix A character array where the resulting postfix expression
 * will be stored. It must be large enough to hold the result.
 */
void convertInfixToPostfix(const char* infix, char* postfix) {
    // Using a static-sized stack for simplicity, could be dynamic for robustness
    char operator_stack[MAX_EXPRESSION_LENGTH];
    int stack_top = -1; // -1 indicates an empty stack

    int postfix_index = 0; // Index for building the postfix string

    for (int i = 0; infix[i] != '\0'; i++) {
        char current_char = infix[i];

        // Skip whitespace characters
        if (isspace(current_char)) {
            continue;
        }

        // Case 1: Operand
        if (isOperand(current_char)) {
            postfix[postfix_index++] = current_char;
        }
        // Case 2: Opening parenthesis
        else if (current_char == '(') {
            operator_stack[++stack_top] = current_char;
        }
        // Case 3: Closing parenthesis
        else if (current_char == ')') {
            // Pop operators from stack and append to postfix until '(' is found
            while (stack_top != -1 && operator_stack[stack_top] != '(') {
                postfix[postfix_index++] = operator_stack[stack_top--];
            }
            // If stack becomes empty or an opening parenthesis isn't found
            if (stack_top == -1 || operator_stack[stack_top] != '(') {
                fprintf(stderr, "Error: Mismatched parentheses in infix expression!\n");
                // In a real application, you might return an error code or handle this more gracefully.
                // For this example, we'll terminate.
                exit(EXIT_FAILURE);
            }
            stack_top--; // Pop '(' from the stack
        }
        // Case 4: Operator
        else {
            // Pop operators from stack with higher or equal precedence
            // (or strictly higher for left-associativity, but this simple
            //  implementation handles typical associativity fine for basic ops)
            while (stack_top != -1 &&
                   getOperatorPrecedence(operator_stack[stack_top]) >= getOperatorPrecedence(current_char)) {
                postfix[postfix_index++] = operator_stack[stack_top--];
            }
            operator_stack[++stack_top] = current_char; // Push current operator
        }
    }

    // Pop any remaining operators from the stack and append to postfix
    while (stack_top != -1) {
        if (operator_stack[stack_top] == '(') {
            // This means there's an unmatched opening parenthesis
            fprintf(stderr, "Error: Mismatched parentheses in infix expression!\n");
            exit(EXIT_FAILURE);
        }
        postfix[postfix_index++] = operator_stack[stack_top--];
    }

    postfix[postfix_index] = '\0'; // Null-terminate the postfix expression
}

// --- Main Program ---

int main() {
    char infix_expression[MAX_EXPRESSION_LENGTH];
    char postfix_expression[MAX_EXPRESSION_LENGTH];

    printf("Enter the infix expression: ");
    // Using fgets to safely read input, preventing buffer overflows
    if (fgets(infix_expression, sizeof(infix_expression), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    // Remove newline character if present from fgets
    infix_expression[strcspn(infix_expression, "\n")] = '\0';

    convertInfixToPostfix(infix_expression, postfix_expression);

    printf("Postfix expression: %s\n", postfix_expression);

    return EXIT_SUCCESS;
}