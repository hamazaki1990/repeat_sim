from monomer import Monomer


class Tandem_repeat:
    def __init__(self, n, i=None, s=0.0):
        repeats = [Monomer(x) for x in range(n)]
        if i is not None:
            repeats[i] = Monomer(i, 1+s)
        self._repeats = repeats

    def get_ids(self):
        return self._repeats

    def get_fitnesses(self):
        fitness = [x.get_fitness() for x in self._repeats]
        return fitness


def main():
    repeat = Tandem_repeat(5)
    print(repeat.get_ids())
    print(repeat.get_fitnesses())
    repeat2 = Tandem_repeat(6, 1, 0.2)
    print(repeat2.get_ids())
    print(repeat2.get_fitnesses())


if __name__ == '__main__':
    main()
