import pyscipopt as scip

if __name__ == "__main__":
    model = scip.Model()

    model.hideOutput()

    x1 = model.addVar(vtype='C', name='x1')
    x2 = model.addVar(vtype='C', name='x2')
    x3 = model.addVar(vtype='C', name='x3')

    cons_1 = model.addCons(0.2*x1 + 0.5*x2 + 0.4*x3 >= 0.3, name="cons_1")
    cons_2 = model.addCons(0.6*x1 + 0.4*x2 + 0.4*x3 >= 0.5, name="cons_2")
    cons_3 = model.addCons(x1 + x2 + x3 == 1, name="cons_3")
    cons_4 = model.addCons(x1 >= 0, name="cons_4")
    cons_5 = model.addCons(x2 >= 0, name="cons_5")
    cons_6 = model.addCons(x3 >= 0, name="cons_6")

    model.setObjective(0.56*x1 + 0.81*x2 + 0.46*x3, sense="minimize")
    model.optimize()

    print(model.getObjVal())