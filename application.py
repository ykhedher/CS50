import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

registred = []
# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")

# form route get
@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")

# form route post
@app.route("/form", methods=["POST"])
def post_form():
    # user input control
    if not request.form.get('name') or not request.form.get('inputGS') or not request.form.get('customRadio'):
        return render_template("error.html", message="Please provide validate information")
    with open("survey.csv", "a") as file:
        writer = csv.writer(file)
        writer.writerow((request.form.get('name'), request.form.get('inputGS'), request.form.get('customRadio')))
    return redirect("/sheet")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    with open("survey.csv", "r") as file:
        reader = csv.reader(file, delimiter=',')
        registered = list(reader)
    return render_template("registered.html", registered=registered)
