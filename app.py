from fun1 import *
from fun2 import *
from fun3 import *
from fun4 import *
from flask import *
from flask_cors import CORS, cross_origin

app = Flask(__name__)
app.config['SECRET_KEY'] = 'super secret key'
@app.route('/')
def home():
   return render_template("index.html")

@app.route('/login',methods = ['GET'])  
def login():  
      data = request.get_json()
      uname= request.args.get("uname", False)
      passwrd= request.args.get("pass", False)
      
      return "Welcome %s" %uname  
      
@app.route('/stick',methods=['POST','GET'])
def stick():
   datas = request.get_json()
   session['data'] = datas
       
   return "BSDK"
@app.route('/king')
def king():
      print(session.get('data'))
@app.route('/imgfunc',methods=['GET'])
def imgfunc():
      print("karklv")
      vardy = "ksd";
      pVc(power, current)
      
      return jsonify(vardy)



@app.route('/imgfunc1',methods=['GET'])
def imgfunc1():
      print("karklv")
      vardy = "ksd1";
      cVrpm(current,rpm)

      return jsonify(vardy)


@app.route('/imgfunc2',methods=['GET'])
def imgfunc2():
      print("karklv")
      vardy = "ksd2";
      pVrpm(power, rpm)

      return jsonify(vardy)


      
@app.route('/imgfunc3',methods=['GET'])
def imgfunc3():
      print("karklv")
      vardy = "ksd3";
     
      vVrpm(rpm)
      
      return jsonify(vardy)

      


if __name__ == '__main__':
     app.run(debug=True)




