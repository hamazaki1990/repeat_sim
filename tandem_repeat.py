import random
from monomer import Monomer


class Tandem_repeat:

    def __init__(self, repeat_id, length, mutatemonomer=None, s=0.0):
        repeats = [Monomer(x) for x in range(length)]
        if mutatemonomer is not None:
            repeats[mutatemonomer].acquire_mutation(s)
        self.__repeats = repeats
        self.__id = repeat_id

    def get_ids(self):
        return [x.get_id() for x in self.__repeats]

    def get_repeatid(self):
        return self.__id

    def get_length(self):
        return len(self.__repeats)

    def get_scs(self):
        sc = [x.get_sc() for x in self.__repeats]
        return sc

    def get_genotypes(self):
        genotype = [x.get_genotype() for x in self.__repeats]
        return genotype

    def calculate_sc(self):
        l = len(self.__repeats)
        f = [x.get_sc() for x in self.__repeats]
        return sum(f)/l

    def acquire_mutation(self, s=0.0):  # add mutation that raises sc by s
        i = random.randrange(len(self.__repeats))
        self.__repeats[i] = self.__repeats[i].acquire_mutation(s)
        return self

    def slippage(self):
        if self.get_length() == 1:
            pass
        else:
            r = random.random()
            if r < 0.5:
                i = random.randrange(self.get_length())
                self.__repeats.pop(i)
            else:
                i = random.randrange(self.get_length())
                dup = self.__repeats[i]
                self.__repeats.insert(i, dup)
        return self

    def select_partial(self, i, j=None):
        if j is None:
            return self.__repeats[i]
        else:
            return self.__repeats[i:j]

    def conversion(self, i, monomer):
        self.__repeats[i] = monomer
        return self

    def crossing_over(self, i, repeat):
        self.__repeats = self.__repeats[0:i]+repeat
        return self


def main():
    repeat = Tandem_repeat(1, 5, 1)
    print(repeat.get_ids())
    print(repeat.get_scs())
    print(repeat.get_length())
    print(repeat.get_genotypes())
    print(repeat.calculate_sc())
    repeat2 = repeat.acquire_mutation(0.1)
    print(repeat2.get_ids())
    print(repeat2.get_scs())
    print(repeat2.get_genotypes())
    print(repeat2.calculate_sc())
    repeat3 = repeat2.acquire_mutation(0.2)
    print(repeat3.get_ids())
    print(repeat3.get_scs())
    print(repeat3.get_genotypes())
    print(repeat3.calculate_sc())
    repeat4 = repeat3.slippage()
    print(repeat4.get_ids())
    print(repeat4.get_scs())
    print(repeat4.get_genotypes())
    print(repeat4.calculate_sc())
    repeat = Tandem_repeat(1, 6, 0)
    print(repeat.get_ids())
    print(repeat.get_genotypes())
    print(repeat.select_partial(1))
    print(repeat.select_partial(1, 3))
    print(repeat3.crossing_over(2, repeat2.select_partial(1, 3)).get_ids())
    for x in range(20):
        repeat.conversion(random.randrange(6),
                          repeat.select_partial(random.randrange(6)))
        print(repeat.get_ids())
        print(repeat.get_genotypes())


if __name__ == '__main__':
    main()
