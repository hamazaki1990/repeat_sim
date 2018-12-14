import random


class Monomer:

    def __init__(self, id_number, sc=1.0):
        self.__monomer_id = id_number
        self.__monomer_sc = sc
        self.__monomer_genotype = []

    def get_id(self):
        return self.__monomer_id

    def get_sc(self):
        return self.__monomer_sc

    def get_genotype(self):
        return self.__monomer_genotype

    def acquire_mutation(self, s=0.0):
        self.__monomer_genotype.append(random.random())
        self.__monomer_sc += s
        return self

    def __repr__(self):
        return "Monomer(id:{})".format(self.__monomer_id)


def main():
    test = Monomer(1)
    test1 = Monomer(1)
    print(str(test.get_id() == test1.get_id()))
    print(str(test.get_sc() == test1.get_sc()))
    print(str(test.get_genotype() == test1.get_genotype()))
    print(str(test == test1))
    print(test.get_sc())
    test2 = test.acquire_mutation()
    print(test2.get_id())
    print(test2.get_genotype())
    print(test2.get_sc())
    test3 = test.acquire_mutation(0.2)
    print(test3.get_id())
    print(test3.get_genotype())
    print(test3.get_sc())
    test4 = test3.acquire_mutation(-0.1)
    print(test4.get_id())
    print(test4.get_genotype())
    print(test4.get_sc())
    print(test4)


if __name__ == '__main__':
    main()
