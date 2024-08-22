#2877. Create a DataFrame from List
import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    df=pd.DataFrame(student_data,columns=["student_id","age"])
    return df;

#2878. Get the Size of a DataFrame
import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    row_count=players.shape[0]
    col_count=players.shape[1]
    return [row_count,col_count]

#2879. Display the First Three Rows
import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    df=employees.head(3)
    return df

#2880. Select Data
import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    # return students.loc[students["student_id"] == 101, ["name", "age"]]
    # # OR
     return students.loc[students["student_id"] == 101, "name" :]
    # # OR
    # return students[students['student_id'] == 101][['name', 'age']]:
    
