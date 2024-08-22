#Pandas Data Structure
#2877. Create a DataFrame from List
import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    df=pd.DataFrame(student_data,columns=["student_id","age"])
    return df;

--------------------------------------------------------------------------------


#Data Inspection
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
    
-----------------------------------------------------------------------
#Data Selecting
#2880. Select Data
import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    # return students.loc[students["student_id"] == 101, ["name", "age"]]
    # # OR
     return students.loc[students["student_id"] == 101, "name" :]
    # # OR
    # return students[students['student_id'] == 101][['name', 'age']]:


#2881. Create a New Column
import pandas as pd

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees['salary'] * 2
    return employees

--------------------------------------------------------------

#Data Cleaning
#2882. Drop Duplicate Rows
import pandas as pd

def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    return customers.drop_duplicates('email')


#2883. Drop Missing Data
import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    newDf=students.dropna(subset="name");
    return newDf


#2884. Modify Columns
import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees["salary"]=2*employees["salary"]
    return employees


#2885. Rename Columns
import pandas as pd

def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
     students.rename(columns={'id': 'student_id',
    'first': 'first_name',
    'last': 'last_name',
    'age': 'age_in_years'}, inplace=True)
     return students


#2886. Change Data Type
import pandas as pd

def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students=students.astype({'grade':int})
    return students


#2887. Fill Missing Data
import pandas as pd

def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products["quantity"].fillna(0,inplace=True)
    return products


-----------------------------------------------------------
#Table Reshaping
#2888. Reshape Data: Concatenate
import pandas as pd

def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    return pd.concat([df1,df2])


#2889. Reshape Data: Pivot
import pandas as pd

def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    df = weather.pivot(index = "month", columns = "city", values = 'temperature')

    return df

