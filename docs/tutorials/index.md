---
layout: default
title: Tutorials
nav_order: 2
has_children: true
permalink: /tutorials/
---

# C++ Programming Tutorials

Welcome to the tutorials section. Here you'll find comprehensive guides to help you learn C++ and Object-Oriented Programming concepts.

## Structure

Each module is broken down into smaller, manageable parts that build upon each other. You'll find:

- Detailed explanations of concepts
- Code examples
- Practice exercises
- Solutions to exercises

## Available Modules

{% for module in site.tutorials %}
  {% if module.title contains "Module" %}
    - [{{ module.title }}]({{ module.url | relative_url }})
  {% endif %}
{% endfor %}

## Getting Started

Start with [Module 1: Introduction to Programming and C++]({{ site.baseurl }}/tutorials/module1) and work your way through each module sequentially. Each module builds upon concepts from previous modules.
