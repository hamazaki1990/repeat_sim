import random
import copy


class Monomer:
    mutationrate = 1

    def __init__(self, id_number, fitness=1.0):
        self.__id = id_number
        self.__fitness = fitness
        self.__genotype = []

    def get_id(self):
        return self.__id

    def get_fitness(self):
        return self.__fitness

    def get_genotype(self):
        return self.__genotype

    def copy_self(self):
        next_ind = copy.deepcopy(self)
        return next_ind

    def acquire_mutation(self, s=0.0):
        r = random.random()
        next_ind = self.copy_self()
        next_genotype = next_ind.__genotype
        next_fitness = next_ind.__fitness
        if r < Monomer.mutationrate:
            next_genotype.append(random.random())
            next_fitness += s
        next_ind.__genotype = next_genotype
        next_ind.__fitness = next_fitness
        return next_ind

    def __repr__(self):
        return "Monomer(id:{})".format(self.__id)


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
