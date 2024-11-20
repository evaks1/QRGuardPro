import os
import sys

sys.path.insert(0, os.path.abspath('../..'))

# Project information
project = 'QRGuardPro'
author = 'QRGuardPro Team'

extensions = [
    'breathe'
]

# Breathe 
breathe_projects = {
    "QRGuardPro": "../../build/docs/xml"  
}
breathe_default_project = "QRGuardPro"

templates_path = ['_templates']
exclude_patterns = []

# HTML output
html_theme = 'alabaster'