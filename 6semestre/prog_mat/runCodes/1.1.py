    
import pyscipopt as scip

if __name__ == "__main__":
    model = scip.Model()

    model.hideOutput()

    x1 = model.addVar(vtype='C', name='x1')
    x2 = model.addVar(vtype='C', name='x2')

    cons_1 = model.addCons(x1 + x2 <= 4, name="cons_1")
    cons_2 = model.addCons(x1 <= 2, name="cons_2")
    cons_3 = model.addCons(x2 <= 3, name="cons_3")
    cons_4 = model.addCons(x1 >= 0, name="cons_4")
    cons_5 = model.addCons(x2 >= 0, name="cons_5")

    model.setObjective(x1 + 2*x2, sense="maximize")
    model.optimize()

    print(model.getObjVal())

