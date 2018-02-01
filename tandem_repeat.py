from monomer import Monomer


class Tandem_repeat:
    def __init__(self, l, i=None, s=0.0):
        repeats = [Monomer(x) for x in range(l)]
        if i is not None:
            repeats[i] = Monomer(i, 1+s)
        self._repeats = repeats

    def get_ids(self):
        return self._repeats

    def get_length(self):
        return len(self._repeats)

    def get_fitnesses(self):
        fitness = [x.get_fitness() for x in self._repeats]
        return fitness

    def cal_fitness(self):
        l = len(self._repeats)
        f = [x.get_fitness() for x in self._repeats]
        return sum(f)/l


def main():
    repeat = Tandem_repeat(5)
    print(repeat.get_ids())
    print(repeat.get_fitnesses())
    print(repeat.get_length())
    repeat2 = Tandem_repeat(6, 1, 0.2)
    print(repeat2.get_ids())
    print(repeat2.get_fitnesses())
    print(repeat2.get_length())
    print(repeat2.cal_fitness())

if __name__ == '__main__':
    main()
