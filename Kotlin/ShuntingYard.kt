import java.util.Stack

class ShuntingYard {

    fun main(args: Array<String>) {
        val infix = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3"
        System.out.printf("infix:   %s%n", infix)
        System.out.printf("postfix: %s%n", infixToPostfix(infix))
    }

    internal fun infixToPostfix(infix: String): String {
        /* To find out the precedence, we take the index of the
           token in the ops string and divide by 2 (rounding down).
           This will give us: 0, 0, 1, 1, 2 */
        val ops = "-+/*^"

        val sb = StringBuilder()
        val s = Stack()

        for (token in infix.split("\\s")) {
            if (token.isEmpty())
                continue
            val c = token.charAt(0)
            val idx = ops.indexOf(c)

            // check for operator
            if (idx != -1) {
                if (s.isEmpty())
                    s.push(idx)
                else {
                    while (!s.isEmpty()) {
                        val prec2 = s.peek() / 2
                        val prec1 = idx / 2
                        if (prec2 > prec1 || prec2 == prec1 && c != '^')
                            sb.append(ops.charAt(s.pop())).append(' ')
                        else
                            break
                    }
                    s.push(idx)
                }
            } else if (c == '(') {
                s.push(-2) // -2 stands for '('
            } else if (c == ')') {
                // until '(' on stack, pop operators.
                while (s.peek() !== -2)
                    sb.append(ops.charAt(s.pop())).append(' ')
                s.pop()
            } else {
                sb.append(token).append(' ')
            }
        }
        while (!s.isEmpty())
            sb.append(ops.charAt(s.pop())).append(' ')
        return sb.toString()
    }
}