from tandem_repeat import Tandem_repeat
import random
import copy


def calculate_ave(seq):
    return sum(seq)/len(seq)


def calculate_var(seq):
    ave = calculate_ave(seq)
    sqd = [(seq[x] - ave)**2 for x in range(len(seq))]
    return sum(sqd)/len(seq)


class Diploid:
    mutationrate = 0
    sliprate = 0.2
    conversrate = 0.4
    crossingrate = 0.4

    def __init__(self, repeat1, repeat2=None):
        if repeat2 is None:
            self._paternal = repeat1
            self._maternal = copy.deepcopy(repeat1)
        else:
            self._paternal = repeat1
            self._maternal = repeat2

    def get_ind_id(self):
        return [self._paternal.get_repeatid(), self._maternal.get_repeatid()]

    def get_repeatids(self):
        ids = [self._paternal.get_ids(),
               self._maternal.get_ids()]
        return ids

    def get_ind_repeatlengths(self):
        length = [self._paternal.get_length(),
                  self._maternal.get_length()]
        return length

    def get_ind_fitnesses(self):
        fitnesses = [self._paternal.get_fitnesses(),
                     self._maternal.get_fitnesses()]
        return fitnesses

    def get_ind_genotypes(self):
        genotype = [self._paternal.get_genotypes(),
                    self._maternal.get_genotypes()]
        return genotype

    def calculate_ind_fitness(self):
        pa_fitness = self._paternal.calculate_fitness()
        ma_fitness = self._maternal.calculate_fitness()
        return calculate_ave([pa_fitness, ma_fitness])

    def copy_self(self):
        return copy.deepcopy(self)

    def acquire_mutation(self, s=0.0):  # add mutation that raises fitness by s
        r = random.random()
        c_self = self.copy_self()
        if r < 0.5:
            c_self._paternal.acquire_mutation()
        else:
            c_self._maternal.acquire_mutation()
        return c_self

    def slippage(self):
        r = random.random()
        c_self = self.copy_self()
        if r < 0.5:
            c_self._paternal.slippage()
        else:
            c_self._maternal.slippage()
        return c_self

    def conversion(self):
        r = random.random()
        lp = self._paternal.get_length()
        lm = self._maternal.get_length()
        c_self = self.copy_self()
        if r < 0.25:
            i = random.randrange(lp)
            j = random.randrange(lp)
            c_self._paternal.conversion(i, c_self._paternal.select_partial(j))
        elif r < 0.5:
            i = random.randrange(lp)
            j = random.randrange(lm)
            c_self._paternal.conversion(i, c_self._maternal.select_partial(j))
        elif r < 0.5:
            i = random.randrange(lm)
            j = random.randrange(lp)
            c_self._maternal.conversion(i, c_self._paternal.select_partial(j))
        elif r < 0.75:
            i = random.randrange(lm)
            j = random.randrange(lm)
            c_self._maternal.conversion(i, c_self._maternal.select_partial(j))
        return c_self

    def crossing_over(self):
        lp = self._paternal.get_length()
        lm = self._maternal.get_length()
        i = random.randrange(lp)
        j = random.randrange(lm)
        c_self = self.copy_self()
        p_latter = c_self._paternal.select_partial(i, lp)
        m_latter = c_self._maternal.select_partial(j, lm)
        c_self._paternal.crossing_over(i, m_latter)
        c_self._maternal.crossing_over(j, p_latter)
        return c_self

    def replicate_error(self):
        error = [Diploid.mutationrate, Diploid.sliprate,
                 Diploid.conversrate, Diploid.crossingrate]
        errorrate = [sum(error[:i]) for i in range(1, len(error) + 1)]
        r = random.random()
        if r < errorrate[0]:
            return self.acquire_mutation()
        elif r < errorrate[1]:
            return self.slippage()
        elif r < errorrate[2]:
            return self.conversion()
        elif r < errorrate[3]:
            return self.crossing_over()
        else:
            return self

    def make_zygote(self):
        r = random.random()
        if r < 0.5:
            return self._paternal
        else:
            return self._maternal


def main():
    test = Diploid(Tandem_repeat(1, 3, 2), Tandem_repeat(1, 3, 2))
    print(test.get_ind_repeatids())
    print(test.get_ind_genotypes())
    print(test.calculate_ind_fitness())

    test2 = test.acquire_mutation()
    print(test2.get_ind_repeatids())
    print(test2.get_ind_genotypes())
    print(test2.calculate_ind_fitness())

    test2 = test.slippage()
    print(test2.get_ind_repeatids())
    print(test2.get_ind_genotypes())

    test2 = test.conversion()
    print(test2.get_ind_repeatids())
    print(test2.get_ind_genotypes())

    test2 = test.crossing_over()
    print(test2.get_ind_repeatids())
    print(test2.get_ind_genotypes())

    print("20generation")
    test = Diploid(Tandem_repeat(1, 6), Tandem_repeat(1, 6, 3))
    for i in range(20):
        print(test.get_ind_repeatids())
        print(test.get_ind_genotypes())
        test = test.replicate_error()


if __name__ == '__main__':
    main()
