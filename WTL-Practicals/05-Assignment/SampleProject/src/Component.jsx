function DisplayMyName(){
    return (
        <>                      {/* function can return a single thing, so return multiple thing we use the concept of fragment , in which empty tags are used to encapsulate multiple things*/}
    <h1>My Name is Suraj</h1>
    <h1 style={ { color:'red' , border:'4px solid white'}}>My Age is 20</h1>
      
</>
)
}

export default DisplayMyName


{/* 
    Two Type Of Export : 
    1)default export : can import with any name 
    Export Syntax : export default FunctionName
    import syntax : import AnyName from '/filename.jsx'
    2)Named Export : requires same name when importing
    syntax : 
        export function NamePrint(){
            return(
                <>
                    <h1>Suraj</h1>
                </>
            )
        }

    Import Syntax :
        import NamePrint from 'Path/Filename.jsx'

    Execute the function after importing
        <NamePrint />      or      NamePrint()


    */}
