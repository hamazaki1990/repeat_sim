import random
import copy


class Monomer:

    def __init__(self, id_number, fitness=1.0):
        self.__monomer_id = id_number
        self.__monomer_fitness = fitness
        self.__monomer_genotype = []

    def get_id(self):
        return self.__monomer_id

    def get_fitness(self):
        return self.__monomer_fitness

    def get_genotype(self):
        return self.__monomer_genotype

    def copy_self(self):
        return copy.deepcopy(self)

    def acquire_mutation(self, s=0.0):
        self.__monomer_genotype.append(random.random())
        self.__monomer_fitness += s
        return self

    def __repr__(self):
        return "Monomer(id:{})".format(self.__monomer_id)


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
    print(test4)


if __name__ == '__main__':
    main()
