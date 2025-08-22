def decimal_to_binary(decimal_num):
    """Converts a decimal number to its binary representation."""
    return bin(decimal_num)[2:]  # [2:] to remove the "0b" prefix


def bitwise_and(num1, num2):
    """Performs bitwise AND operation."""
    return num1 & num2


def bitwise_or(num1, num2):
    """Performs bitwise OR operation."""
    return num1 | num2


def bitwise_xor(num1, num2):
    """Performs bitwise XOR operation."""
    return num1 ^ num2


def bitwise_not(num):
    """Performs bitwise NOT operation."""
    #  bitwise NOT is a little tricky in Python due to how negative numbers are represented.
    #  This is a common way to handle it for practical purposes, limiting the result to a manageable range.
    return ~num & 0xFF  # Limiting to 8 bits for practical demonstration


def left_shift(num, shift_by):
    """Performs left shift operation."""
    return num << shift_by


def right_shift(num, shift_by):
    """Performs right shift operation."""
    return num >> shift_by


def main():
    """Main function to run the bitwise operations program."""

    while True:
        print("\nBitwise Operations Menu:")
        print("1. AND (&)")
        print("2. OR (|)")
        print("3. XOR (^)")
        print("4. NOT (~)")
        print("5. Left Shift (<<)")
        print("6. Right Shift (>>)")
        print("7. Exit")

        choice = input("Enter your choice (1-7): ")

        if choice == '7':
            print("Exiting program.")
            break

        if choice in ('1', '2', '3'):
            num1 = int(input("Enter the first number: "))
            num2 = int(input("Enter the second number: "))

            if choice == '1':
                result = bitwise_and(num1, num2)
                operation_name = "AND"
            elif choice == '2':
                result = bitwise_or(num1, num2)
                operation_name = "OR"
            else:
                result = bitwise_xor(num1, num2)
                operation_name = "XOR"

            print(f"\n{operation_name} Result:")
            print(f"Decimal: {result}")
            print(f"Binary: {decimal_to_binary(result)}")

        elif choice == '4':
            num = int(input("Enter a number: "))
            result = bitwise_not(num)
            print("\nNOT Result:")
            print(f"Decimal: {result}")
            print(f"Binary: {decimal_to_binary(result)}")

        elif choice in ('5', '6'):
            num = int(input("Enter a number: "))
            shift_by = int(input("Enter the number of bits to shift by: "))

            if choice == '5':
                result = left_shift(num, shift_by)
                operation_name = "Left Shift"
            else:
                result = right_shift(num, shift_by)
                operation_name = "Right Shift"

            print(f"\n{operation_name} Result:")
            print(f"Decimal: {result}")
            print(f"Binary: {decimal_to_binary(result)}")

        else:
            print("Invalid choice. Please enter a number between 1 and 7.")


if __name__ == "__main__":
    main()
    