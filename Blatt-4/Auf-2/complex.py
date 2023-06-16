class komplex:
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    def __add__(self, other):
        real_part = self.real + other.real
        imag_part = self.imag + other.imag
        return komplex(real_part, imag_part)

    def __sub__(self, other):
        real_part = self.real - other.real
        imag_part = self.imag - other.imag
        return komplex(real_part, imag_part)

    def __mul__(self, other):
        real_part = self.real * other.real - self.imag * other.imag
        imag_part = self.real * other.imag + self.imag * other.real
        return komplex(real_part, imag_part)


def main():
    z1 = komplex(2, 3)
    z2 = komplex(4, 5)
    result_add = z1 + z2
    print("Addition:", result_add.real, "+", result_add.imag, "i")
    result_sub = z1 - z2
    print("Subtraktion:", result_sub.real, "+", result_sub.imag, "i")
    result_mul = z1 * z2
    print("Multiplikation:", result_mul.real, "+", result_mul.imag, "i")


if __name__ == "__main__":
    main()
