class Monomer:

    def __init__(self, n, f=1.0):
        self._id = n
        self._fitness = f
        self._genotype = []

    def get_id(self):
        return self._id

    def get_fitness(self):
        return self._fitness

    def get_genotype(self):
        return self._genotype

    def __repr__(self):
        return str(self._id)


def main():
    test = Monomer(1)
    print(test.get_fitness())
    test2 = test.acquire_mutation()
    print(test2.get_id())
    print(test2.get_genotype())
    print(test2.get_fitness())
    test3 = test.acquire_mutation(0.2)
    print(test3.get_id())
    print(test3.get_genotype())
    print(test3.get_fitness())
    test4 = test3.acquire_mutation(-0.1)
    print(test4.get_id())
    print(test4.get_genotype())
    print(test4.get_fitness())


if __name__ == '__main__':
    main()
